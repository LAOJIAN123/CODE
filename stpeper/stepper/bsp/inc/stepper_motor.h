/*************************************************************************************
 * Description: BSP�������
 * Version: 
 * Author: ��־��
 * Date: 2024-02-16 16:04:12
 * LastEditors: ��־��
 * LastEditTime: 2024-03-20 11:00:34
 *************************************************************************************/
#ifndef STEPPER_MOTOR
#define  STEPPER_MOTOR

#define stepper_tim   htim3


#define STEP_ANGLE 1.8  //�����
#define PRECISION  32    //ϸ�־���

#define GET_PSC       stepper_tim.Instance->PSC       //��ȡ��ǰTIM��Ԥ��Ƶϵ��
#define GET_TIM_F     (timclock /  GET_PSC)            //��õ�ǰTIMƵ��
#define RAD2PWM(A)    (6.0*A*PRECISION/STEP_ANGLE)  // rad/minת��Ϊ������


void motor_enable(void);
void motor_disable(void);
void step_run(void);
void stepper_init(void);
void Step_Ver(void);
void Set_Speed(void);
void Set_Time(void);
void Set_Stop_Time(void);
void Set_Ver_Time(void);


enum VER_STATUS //���ת��״̬ö��
{
    Foreward = 1, //��ת
    Reversal  //��ת
};

enum OPEN_STATUS //�����������״̬ö��
{
    OFF = 1, //��ת
    ON  //��ת
};

struct stepper_motor  //�������״̬

{
    enum VER_STATUS ver;
    enum OPEN_STATUS open_flag;
};


#endif

