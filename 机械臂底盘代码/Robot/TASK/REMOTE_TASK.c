/*************************************************************************************
 * Description: 
 * Version: 
 * Author: ��־��
 * Date: 2023-12-14 17:21:11
 * LastEditors: ��־��
 * LastEditTime: 2023-12-15 15:56:41
 *************************************************************************************/

#include "main.h"
#include "REMOTE_TASK.h"
#include "moto_control.h"
#include "ps2.h"
extern Machine_chassis_t Machine_chassis;  //���õ��̶������

extern u8 Data[9];                         //����ң�ؽ�������



void Remote_Task(void const * argument)
{
	//PS2_SetInit();
	while(1)
	{
			
			if(!PS2_RedLight())
			{
				PS2_ReadREDData(); //��ȡң������
				//��ң�����ݸ�ֵ�����̽ṹ��
				Machine_chassis.moto_x = PS2_AnologData(LEFT_X)    -128 ;    
				Machine_chassis.moto_y = -(PS2_AnologData(LEFT_Y) -127) ;
				Machine_chassis.moto_yaw = PS2_AnologData(RIGHT_X) -128 ;
				
			}
			PS2_ClearData();      //�������
			HAL_Delay(5);
	}
}

