/*************************************************************************************
 * Description: �ۺ�ֱ����ˢ���Ӳ������
 * Version: 0.1
 * Author: ��־��
 * Date: 2023-12-12 21:18:02
 * LastEditors: ��־��
 * LastEditTime: 2023-12-14 18:17:16
 *************************************************************************************/


#include "main.h"
#include "moto_control.h"

//���ת�ٱ���
//Advise15~25kHz
//TIM3ʱ��ԴΪAPB1---ϵͳʱ��/2----ĿǰΪ36M
extern TIM_HandleTypeDef htim3;
extern Machine_chassis_t Machine_chassis;

void MOTO_RUN(Machine_chassis_t *var1)
{
        __HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_1,( (float)var1->motor[0].current / 100)*2100);   
				CS_1;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_2,( (float)var1->motor[1].current / 100)*2100);  
				CS_2;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_3,( (float)var1->motor[2].current / 100)*2100);  
				CS_3;
				__HAL_TIM_SET_COMPARE(&htim3,TIM_CHANNEL_4,( (float)var1->motor[3].current / 100)*2100);  
				CS_4;
}



void MC_Solving(Machine_chassis_t *Machine_chassis)
{

		Machine_chassis->motor[0].speed = (-Machine_chassis->moto_y - Machine_chassis->moto_x + Machine_chassis->moto_yaw) * moto_ride;
		Machine_chassis->motor[1].speed = (Machine_chassis->moto_y - Machine_chassis->moto_x + Machine_chassis->moto_yaw) * moto_ride;
		Machine_chassis->motor[2].speed = (-Machine_chassis->moto_y + Machine_chassis->moto_x + Machine_chassis->moto_yaw) * moto_ride;
		Machine_chassis->motor[3].speed = (Machine_chassis->moto_y + Machine_chassis->moto_x + Machine_chassis->moto_yaw) * moto_ride;
		//��������ת
		Machine_chassis->motor[0].direction = DIRE(Machine_chassis->motor[0].speed) * Reversal_0;
    Machine_chassis->motor[1].direction = DIRE(Machine_chassis->motor[1].speed) * Reversal_1;
    Machine_chassis->motor[2].direction = DIRE(Machine_chassis->motor[2].speed) * Reversal_2;
    Machine_chassis->motor[3].direction = DIRE(Machine_chassis->motor[3].speed) * Reversal_3;
		
	  Machine_chassis->motor[0].current  =  abs(Machine_chassis->motor[0].speed);
	  Machine_chassis->motor[1].current  =  abs(Machine_chassis->motor[1].speed);
    Machine_chassis->motor[2].current  =  abs(Machine_chassis->motor[2].speed);
    Machine_chassis->motor[3].current  =  abs(Machine_chassis->motor[3].speed);
}                                      