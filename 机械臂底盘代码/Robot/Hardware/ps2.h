/*************************************************************************************
 * Description: 
 * Version: 
 * Author: 林志坚
 * Date: 2023-12-18 15:31:59
 * LastEditors: 林志坚
 * LastEditTime: 2023-12-21 15:32:45
 *************************************************************************************/
#ifndef PS2
#define PS2

/*********************************************************
Copyright (C), 2015-2025, YFRobot.
www.yfrobot.com
File：PS2驱动程序
Author：pinggai    Version:1.1     Data:2015/10/20
Description: PS2驱动程序
             增加功能：
			 1、软件设置“红灯模式”、“绿灯模式”，并可以设置“保存”，通过手柄“模式按键”无法改变
			 2、设置手柄震动：通过数值的设置，改变左侧大震动电机震动频率。
			                  通过数值的设置，开关右侧小震动电机。
History:  
V1.0: 	2015/05/16
1、手柄解码，识别按键值，读取模拟值。   
https://blog.csdn.net/weixin_44793491/article/details/105781595
**********************************************************/	 

#include "main.h" 

//手柄接口初始化    输入  	DAT->PA0
//                 输出   CMD->PA1   CS->PA4     CLK->PA5
#define CMD_GPIO_Port GPIOA
#define CS_GPIO_Port  GPIOA
#define CLK_GPIO_Port GPIOA
#define DAT_GPIO_Port GPIOA

#define CMD_Pin GPIO_PIN_1
#define CS_Pin  GPIO_PIN_4
#define CLK_Pin GPIO_PIN_5
#define DAT_Pin GPIO_PIN_0

#define DI    HAL_GPIO_ReadPin(DAT_GPIO_Port,DAT_Pin)                    //PA1  输入
                                                                                                                                                                            
#define DO_H  HAL_GPIO_WritePin(CMD_GPIO_Port,CMD_Pin,GPIO_PIN_SET)     //命令位高
#define DO_L  HAL_GPIO_WritePin(CMD_GPIO_Port,CMD_Pin,GPIO_PIN_RESET)     //命令位低
                                                                           
#define CS_H  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET)         //CS拉高
#define CS_L  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET)       //CS拉低
                                                                           
#define CLK_H HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin,GPIO_PIN_SET)      //时钟拉高
#define CLK_L HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin,GPIO_PIN_RESET)     //时钟拉低


//These are our button constants
#define PSB_SELECT      1
#define PSB_L3          2
#define PSB_R3          3
#define PSB_START       4
#define PSB_PAD_UP      5
#define PSB_PAD_RIGHT   6
#define PSB_PAD_DOWN    7
#define PSB_PAD_LEFT    8
#define PSB_L2          9
#define PSB_R2          10
#define PSB_L1          11
#define PSB_R1          12
#define PSB_GREEN       13
#define PSB_RED         14
#define PSB_BLUE        15
#define PSB_PINK        16
#define PSB_TRIANGLE    13
#define PSB_CIRCLE      14
#define PSB_CROSS       15
#define PSB_SQUARE      26

//RED MODE 
#define LEFT_X 5
#define LEFT_Y 8
#define RIGHT_X 7
#define RIGHT_Y 6


//#define WHAMMY_BAR		8

//These are stick values
#define PSS_RX 7                //右摇杆X轴数据
#define PSS_RY 8
#define PSS_LX 5
#define PSS_LY 6


//extern u8 Data[9];
extern u16 MASK[16];
extern u16 Handkey;

void PS2_Init(void);
u8 PS2_RedLight(void);   //判断是否为红灯模式
void PS2_ReadData(void); //读手柄数据
void PS2_ReadREDData(void); //读取红色手柄数据
void PS2_Cmd(u8 CMD);		  //向手柄发送命令
u8 PS2_DataKey(void);		  //按键值读取
u8 PS2_AnologData(u8 button); //得到一个摇杆的模拟量
void PS2_ClearData(void);	  //清除数据缓冲区
void PS2_Vibration(u8 motor1, u8 motor2);//振动设置motor1  0xFF开，其他关，motor2  0x40~0xFF
void delay_us(uint32_t us);

void PS2_EnterConfing(void);	 //进入配置
void PS2_TurnOnAnalogMode(void); //发送模拟量
void PS2_VibrationMode(void);    //振动设置
void PS2_ExitConfing(void);	     //完成配置
void PS2_SetInit(void);		     //配置初始化

#endif



