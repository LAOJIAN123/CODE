#include "Menu.h"
#include "stepper_motor.h"

char *run_status = "运行";

extern const uint8_t goutou[];
int8_t Menu_Start(int8_t Shift)
{
	if (Shift == 0)
	{
		if (Menu_Global.RunningMenu->isInit)
		{
			return 0;
		}
		else
		{
			Menu_RunMainMenu();
			return 1;
		}
	}
	else if (Shift == 1)
	{
		Menu_RunMainMenu();
	}
	else // if(Shift == -1)
	{
		Menu_Global.RunningMenu->isInit = 1;
		return 0;
	}
	return 0;
}

/*创建选项列表*/
struct Option_Class Menu_StartOptionList[] = {
	{"<<<"},
	{"转动", Step_Ver},
	{"参数设置", Menu_RunToolsMenu},
	{"系统设置", Menu_RunSettingMenu}, // 设置
	{"关于", Menu_Information},		   // 信息
	{".."}};

/*创建开始菜单对象*/
struct Menu_Class Menu_StartMenu = {.isInit = 1};

void Menu_RunMainMenu(void)
{
	if (Menu_StartMenu.isInit) // 由于开始菜单没有上级, 需手动配置部分参数;
	{
		Menu_MenuClassInit(&Menu_StartMenu, Menu_StartOptionList);
		/*手动配置区*******/
		Menu_StartMenu.Target_Window_X = 0;
		Menu_StartMenu.Window_X = 0;
		Menu_StartMenu.Window_Y = 64;
		Menu_Global.Cursor_Actual_X = 0;
		Menu_Global.Cursor_Actual_Y = 64;

		/*******手动配置区*/
	}

	Menu_RunWindow(&Menu_StartMenu);
}
/*创建选项列表*/
struct Option_Class Menu_ToolsOptionList[] = {
	{"<<<"},
	{"设置转速[60]", Set_Speed}, // 6-1 定时器定时中断
	{"转动时间[1]",Set_Time},			 // 6-6 输入捕获模式测频率
	{"停转时间[0]",Set_Stop_Time},
	{"反转周期[0]",Set_Ver_Time},
	{".."}};
void Menu_RunToolsMenu(void)
{

	/*创建菜单对象*/
	static struct Menu_Class Menu_ToolsMenu = {.isInit = 1}; // 赋值初始化

	if (Menu_ToolsMenu.isInit)
	{
		Menu_MenuClassInit(&Menu_ToolsMenu, Menu_ToolsOptionList);
		/*手动配置区*******/

		/*******手动配置区*/
	}

	Menu_RunWindow(&Menu_ToolsMenu);
}

void Menu_Information(void)
{
	float Angle = 3640;
	while (1)
	{
		OLED_Clear();

		OLED_ShowImage(88, 8, 32, 32, goutou);
		OLED_Rotation_Block(88 + 16, 8 + 16, 16, Angle);

		Angle += Menu_RollEvent() * 8;

		if (Angle > 1)
		{
			Angle -= Angle / 32 + 1;
		}
		else if (Angle < -1)
		{
			Angle -= Angle / 32 - 1;
		}
		else
		{
			Angle = 0;
		}
		// Angle += 2;
		// Angle %= 360;

		OLED_ShowString(2, 0, "By:发哥", OLED_8X16);
		OLED_ShowString(2, 32, "胶片滚冲机", OLED_8X16);
		OLED_ShowString(2, 48, "感谢开源：Adam", OLED_8X16);

		OLED_Update();
		if (Menu_EnterEvent())
		{
			return;
		}
		if (Menu_BackEvent())
		{
			return;
		}
	}
}

/**********************************************************/
