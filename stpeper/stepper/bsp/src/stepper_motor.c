/*************************************************************************************
 * Description: BSP步进电机
 * Version: 
 * Author: 林志坚
 * Date: 2024-02-16 16:03:52
 * LastEditors: 林志坚
 * LastEditTime: 2024-02-18 11:45:57
 *************************************************************************************/

#include "main.h"
#include "stepper_motor.h"


extern TIM_HandleTypeDef stepper_tim;
uint32_t timclock = 0;
double addd =0;
char run_s = 0;
void speed_set(int speed)
{
    
}

void position_set(int angle)
{

}


void stepper_init()
{
	timclock =  HAL_RCC_GetPCLK2Freq();    //获取APB2时钟频率，tim3是挂载在APB2上的
}

void step_run(int speed)
{
		
	  addd =(double)GET_TIM_F/(double)RAD2PWM(speed);
    __HAL_TIM_SET_AUTORELOAD(&stepper_tim,(double)GET_TIM_F/(double)RAD2PWM(speed));  //设置重装载值来控制脉冲频率
    __HAL_TIM_SET_COMPARE(&stepper_tim,TIM_CHANNEL_1,stepper_tim.Instance->ARR/2); //占空比百分之50
}


void Step_Ver(void)
{
	if(run_s== 0)
	{
		HAL_TIM_PWM_Start(&htim3,TIM_CHANNEL_1);	
		step_run(60);
	}
	else if(run_s== 255)
	{
		HAL_TIM_PWM_Stop(&htim3,TIM_CHANNEL_1);
	}	
	run_s=~run_s;

}