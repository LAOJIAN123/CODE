/*************************************************************************************
 * Description: 
 * Version: 
 * Author: ��־��
 * Date: 2023-12-18 15:31:59
 * LastEditors: ��־��
 * LastEditTime: 2023-12-21 15:32:45
 *************************************************************************************/
#ifndef PS2
#define PS2

/*********************************************************
Copyright (C), 2015-2025, YFRobot.
www.yfrobot.com
File��PS2��������
Author��pinggai    Version:1.1     Data:2015/10/20
Description: PS2��������
             ���ӹ��ܣ�
			 1��������á����ģʽ�������̵�ģʽ�������������á����桱��ͨ���ֱ���ģʽ�������޷��ı�
			 2�������ֱ��𶯣�ͨ����ֵ�����ã��ı������𶯵����Ƶ�ʡ�
			                  ͨ����ֵ�����ã������Ҳ�С�𶯵����
History:  
V1.0: 	2015/05/16
1���ֱ����룬ʶ�𰴼�ֵ����ȡģ��ֵ��   
https://blog.csdn.net/weixin_44793491/article/details/105781595
**********************************************************/	 

#include "main.h" 

//�ֱ��ӿڳ�ʼ��    ����  	DAT->PA0
//                 ���   CMD->PA1   CS->PA4     CLK->PA5
#define CMD_GPIO_Port GPIOA
#define CS_GPIO_Port  GPIOA
#define CLK_GPIO_Port GPIOA
#define DAT_GPIO_Port GPIOA

#define CMD_Pin GPIO_PIN_1
#define CS_Pin  GPIO_PIN_4
#define CLK_Pin GPIO_PIN_5
#define DAT_Pin GPIO_PIN_0

#define DI    HAL_GPIO_ReadPin(DAT_GPIO_Port,DAT_Pin)                    //PA1  ����
                                                                                                                                                                            
#define DO_H  HAL_GPIO_WritePin(CMD_GPIO_Port,CMD_Pin,GPIO_PIN_SET)     //����λ��
#define DO_L  HAL_GPIO_WritePin(CMD_GPIO_Port,CMD_Pin,GPIO_PIN_RESET)     //����λ��
                                                                           
#define CS_H  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_SET)         //CS����
#define CS_L  HAL_GPIO_WritePin(CS_GPIO_Port,CS_Pin,GPIO_PIN_RESET)       //CS����
                                                                           
#define CLK_H HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin,GPIO_PIN_SET)      //ʱ������
#define CLK_L HAL_GPIO_WritePin(CLK_GPIO_Port,CLK_Pin,GPIO_PIN_RESET)     //ʱ������


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
#define PSS_RX 7                //��ҡ��X������
#define PSS_RY 8
#define PSS_LX 5
#define PSS_LY 6


//extern u8 Data[9];
extern u16 MASK[16];
extern u16 Handkey;

void PS2_Init(void);
u8 PS2_RedLight(void);   //�ж��Ƿ�Ϊ���ģʽ
void PS2_ReadData(void); //���ֱ�����
void PS2_ReadREDData(void); //��ȡ��ɫ�ֱ�����
void PS2_Cmd(u8 CMD);		  //���ֱ���������
u8 PS2_DataKey(void);		  //����ֵ��ȡ
u8 PS2_AnologData(u8 button); //�õ�һ��ҡ�˵�ģ����
void PS2_ClearData(void);	  //������ݻ�����
void PS2_Vibration(u8 motor1, u8 motor2);//������motor1  0xFF���������أ�motor2  0x40~0xFF
void delay_us(uint32_t us);

void PS2_EnterConfing(void);	 //��������
void PS2_TurnOnAnalogMode(void); //����ģ����
void PS2_VibrationMode(void);    //������
void PS2_ExitConfing(void);	     //�������
void PS2_SetInit(void);		     //���ó�ʼ��

#endif



