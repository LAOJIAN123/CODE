/*************************************************************************************
 * Description: BSP步进电机
 * Version: 
 * Author: 林志坚
 * Date: 2024-02-16 16:04:12
 * LastEditors: 林志坚
 * LastEditTime: 2024-03-20 11:00:34
 *************************************************************************************/
#ifndef STEPPER_MOTOR
#define  STEPPER_MOTOR

#define stepper_tim   htim3


#define STEP_ANGLE 1.8  //步距角
#define PRECISION  32    //细分精度

#define GET_PSC       stepper_tim.Instance->PSC       //获取当前TIM的预分频系数
#define GET_TIM_F     (timclock /  GET_PSC)            //获得当前TIM频率
#define RAD2PWM(A)    (6.0*A*PRECISION/STEP_ANGLE)  // rad/min转化为脉冲数


void motor_enable(void);
void motor_disable(void);
void step_run(void);
void stepper_init(void);
void Step_Ver(void);
void Set_Speed(void);
void Set_Time(void);
void Set_Stop_Time(void);
void Set_Ver_Time(void);


enum VER_STATUS //电机转向状态枚举
{
    Foreward = 1, //正转
    Reversal  //反转
};

enum OPEN_STATUS //电机启动缓冲状态枚举
{
    OFF = 1, //正转
    ON  //反转
};

struct stepper_motor  //步进电机状态

{
    enum VER_STATUS ver;
    enum OPEN_STATUS open_flag;
};


#endif

