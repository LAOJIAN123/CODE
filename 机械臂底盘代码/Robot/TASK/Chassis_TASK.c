/*************************************************************************************
 * Description: 
 * Version: 
 * Author: ��־��
 * Date: 2023-12-14 17:22:37
 * LastEditors: ��־��
 * LastEditTime: 2023-12-15 16:01:21
 *************************************************************************************/




#include "main.h"
#include "Chassis_TASK.h"
#include "moto_control.h"


Machine_chassis_t  Machine_chassis; //�������̶���


void Chassis_Task(void const * argument)
{
   while(1)
	{
			MC_Solving(&Machine_chassis);//����
			MOTO_RUN(&Machine_chassis);  //�˶�
			osDelay(1);
	}
}


