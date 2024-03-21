/*************************************************************************************
 * Description: BSP步进电机
 * Version:
 * Author: 林志坚
 * Date: 2024-02-16 16:03:52
 * LastEditors: 林志坚
 * LastEditTime: 2024-03-20 17:22:29
 *************************************************************************************/

#include "main.h"
#include "stepper_motor.h"
#include "bsp_dwt.h"
extern TIM_HandleTypeDef stepper_tim;
uint32_t timclock = 0;
double addd = 0;
char run_s = 0;
int speed = 60; // 默认转速
int8_t ver = -1;
int run_time = 1000;//转动时间单位ms
int start_time = 0;
char motor_enable_flag = 0;
int stop_time = 0;//转动时间单位ms
int smooth_time = 0;

int Smooth = 100;//0-1000ms

struct stepper_motor  motor;

void motor_enable(void)
{
	
	 //__HAL_TIM_SET_AUTORELOAD(&stepper_tim, (double)GET_TIM_F / (double)RAD2PWM(1));
	
	HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);
}
void motor_disable(void)
{
	HAL_TIM_PWM_Stop(&htim3, TIM_CHANNEL_1);
}

void stepper_init()
{
	timclock = HAL_RCC_GetPCLK2Freq(); // 获取APB2时钟频率，tim3是挂载在APB2上的
}

void step_run(void)
{

	addd = (double)GET_TIM_F / (double)RAD2PWM(speed);
	__HAL_TIM_SET_AUTORELOAD(&stepper_tim, (double)GET_TIM_F / (double)RAD2PWM(speed)); // 设置重装载值来控制脉冲频率
	__HAL_TIM_SET_COMPARE(&stepper_tim, TIM_CHANNEL_1, stepper_tim.Instance->ARR / 2);	// 占空比百分之50
}


#include "menu.h"
extern struct Option_Class Menu_StartOptionList[];
void Step_Ver(void)
{
	if (run_s == 0)
	{
		motor_enable_flag = 1;
		Menu_StartOptionList[1].String = "停止";

		start_time = DWT_GetTimeline_ms();
	}
	else if (run_s == 255)
	{
		Menu_StartOptionList[1].String = "转动";
		motor_enable_flag = 0;

	}
	run_s = ~run_s;
}

extern struct Option_Class Menu_ToolsOptionList[];
void Set_Speed(void)
{
	static int8_t Speed = 60;
	if (Speed == 60)
	{
		Menu_ToolsOptionList[1].String = "设置转速[70]";
		Speed += 10;
	}
	else if (Speed == 70)
	{
		Menu_ToolsOptionList[1].String = "设置转速[80]";
		Speed += 10;
	}
	else if (Speed == 80)
	{
		Menu_ToolsOptionList[1].String = "设置转速[90]";
		Speed += 10;
	}
	else if (Speed == 90)
	{
		Menu_ToolsOptionList[1].String = "设置转速[100]";
		Speed += 10;
	}
	else if (Speed == 100)
	{
		Menu_ToolsOptionList[1].String = "设置转速[110]";
		Speed += 10;
	}
	else if (Speed == 110)
	{
		Menu_ToolsOptionList[1].String = "设置转速[120]";
		Speed += 10;
	}
	else
	{
		Menu_ToolsOptionList[1].String = "设置转速[60]";
		Speed = 60;
	}
//	step_run(Speed);
	
	speed = Speed;
}

void Set_Time(void)
{
	static int8_t time = 1;
	if (time == 1)
	{
		Menu_ToolsOptionList[2].String = "转动时间[2]";
		time += 1;
	}
	else  if (time == 2)
	{
		Menu_ToolsOptionList[2].String = "转动时间[4]";
		time += 2;
	}
	else if (time == 4)
	{
		Menu_ToolsOptionList[2].String = "转动时间[6]";
		time += 2;
	}
	else if (time == 6)
	{
		Menu_ToolsOptionList[2].String = "转动时间[8]";
		time += 2;
	}
	else if (time == 8)
	{
		Menu_ToolsOptionList[2].String = "转动时间[10]";
		time += 2;
	}
	else if (time == 10)
	{
		Menu_ToolsOptionList[2].String = "转动时间[12]";
		time += 2;
	}
	else
	{
		Menu_ToolsOptionList[2].String = "转动时间[1]";
		time = 1;
	}
	run_time = time*1000;
}

void Set_Stop_Time(void)
{
	static int8_t time = 0;
	if (time == 0)
	{
		Menu_ToolsOptionList[3].String = "停转时间[1]";
		time += 1;
	}
	else if (time == 1)
	{
		Menu_ToolsOptionList[3].String = "停转时间[2]";
		time += 1;
	}
	else if (time == 2)
	{
		Menu_ToolsOptionList[3].String = "停转时间[4]";
		time += 2;
	}
	else if (time == 4)
	{
		Menu_ToolsOptionList[3].String = "停转时间[6]";
		time += 2;
	}
	else if (time == 6)
	{
		Menu_ToolsOptionList[3].String = "停转时间[8]";
		time += 2;
	}
	else if (time == 8)
	{
		Menu_ToolsOptionList[3].String = "停转时间[10]";
		time += 2;
	}
	else if (time == 10)
	{
		Menu_ToolsOptionList[3].String = "停转时间[12]";
		time += 2;
	}
	else
	{
		Menu_ToolsOptionList[3].String = "停转时间[0]";
		time = 0;
	}
	stop_time = time*1000;
}


void Set_Ver_Time(void)
{
	static int8_t Ver = -1;
	if (Ver == -1)
	{
		Menu_ToolsOptionList[4].String = "反转周期[1]";
		Ver = 0;
	}
	else if (Ver == 0)
	{
		Menu_ToolsOptionList[4].String = "反转周期[2]";
		Ver += 1;
	}
else if (Ver == 1)
	{
		Menu_ToolsOptionList[4].String = "反转周期[3]";
		Ver += 1;
	}
	else if (Ver == 2)
	{
		Menu_ToolsOptionList[4].String = "反转周期[4]";
		Ver += 1;
	}
	else if (Ver == 3)
	{
		Menu_ToolsOptionList[4].String = "反转周期[5]";
		Ver += 1;
	}
	else if (Ver == 4)
	{
		Menu_ToolsOptionList[4].String = "反转周期[6]";
		Ver += 1;
	}
	else
	{
		Menu_ToolsOptionList[4].String = "反转周期[0]";
		Ver = -1;
	}
	ver =Ver;
}