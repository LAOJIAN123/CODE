/*************************************************************************************
 * Description: 
 * Version: 
 * Author: 林志坚
 * Date: 2023-12-14 17:22:37
 * LastEditors: 林志坚
 * LastEditTime: 2023-12-15 16:01:21
 *************************************************************************************/




#include "main.h"
#include "Chassis_TASK.h"
#include "moto_control.h"


Machine_chassis_t  Machine_chassis; //创建底盘对象


void Chassis_Task(void const * argument)
{
   while(1)
	{
			MC_Solving(&Machine_chassis);//解算
			MOTO_RUN(&Machine_chassis);  //运动
			osDelay(1);
	}
}


