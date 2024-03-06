/*************************************************************************************
 * Description: BSP�������
 * Version: 
 * Author: ��־��
 * Date: 2024-02-16 16:04:12
 * LastEditors: ��־��
 * LastEditTime: 2024-02-18 11:56:45
 *************************************************************************************/
#ifndef STEPPER_MOTOR
#define  STEPPER_MOTOR

#define stepper_tim   htim3


#define STEP_ANGLE 1.8  //�����
#define PRECISION  16    //ϸ�־���

#define GET_PSC       stepper_tim.Instance->PSC       //��ȡ��ǰTIM��Ԥ��Ƶϵ��
#define GET_TIM_F     (timclock /  GET_PSC)            //��õ�ǰTIMƵ��
#define RAD2PWM(A)    (6.0*A*PRECISION/STEP_ANGLE)  // rad/minת��Ϊ������


void speed_set(int speed);
void position_set(int angle);
void step_run(int speed);
void stepper_init();
void Step_Ver(void);
#endif