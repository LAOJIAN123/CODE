/*************************************************************************************
 * Description: BSP步进电机
 * Version: 
 * Author: 林志坚
 * Date: 2024-02-16 16:04:12
 * LastEditors: 林志坚
 * LastEditTime: 2024-02-18 11:56:45
 *************************************************************************************/
#ifndef STEPPER_MOTOR
#define  STEPPER_MOTOR

#define stepper_tim   htim3


#define STEP_ANGLE 1.8  //步距角
#define PRECISION  16    //细分精度

#define GET_PSC       stepper_tim.Instance->PSC       //获取当前TIM的预分频系数
#define GET_TIM_F     (timclock /  GET_PSC)            //获得当前TIM频率
#define RAD2PWM(A)    (6.0*A*PRECISION/STEP_ANGLE)  // rad/min转化为脉冲数


void speed_set(int speed);
void position_set(int angle);
void step_run(int speed);
void stepper_init();
void Step_Ver(void);
#endif