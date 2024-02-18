/*************************************************************************************
 * Description: 
 * Version: 
 * Author: 林志坚
 * Date: 2023-12-14 17:21:11
 * LastEditors: 林志坚
 * LastEditTime: 2023-12-15 15:56:41
 *************************************************************************************/

#include "main.h"
#include "REMOTE_TASK.h"
#include "moto_control.h"
#include "ps2.h"
extern Machine_chassis_t Machine_chassis;  //引用底盘对象变量

extern u8 Data[9];                         //引用遥控接收数组



void Remote_Task(void const * argument)
{
	//PS2_SetInit();
	while(1)
	{
			
			if(!PS2_RedLight())
			{
				PS2_ReadREDData(); //读取遥控数据
				//将遥控数据赋值给底盘结构体
				Machine_chassis.moto_x = PS2_AnologData(LEFT_X)    -128 ;    
				Machine_chassis.moto_y = -(PS2_AnologData(LEFT_Y) -127) ;
				Machine_chassis.moto_yaw = PS2_AnologData(RIGHT_X) -128 ;
				
			}
			PS2_ClearData();      //清除数据
			HAL_Delay(5);
	}
}

