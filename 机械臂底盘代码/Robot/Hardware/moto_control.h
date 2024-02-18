#ifndef MOTO_CONTROL
#define MOTO_CONTROL


#include "main.h"

#define moto_ride 1  //电机倍率



//RIGH为正转BACK为反转
#define RIGHT     1
#define BACK      -1

#define Reversal_0    RIGHT
#define Reversal_1    RIGHT
#define Reversal_2    BACK
#define Reversal_3    BACK


#define CS_1_GPIO GPIOA
#define CS_2_GPIO GPIOA
#define CS_3_GPIO GPIOB
#define CS_4_GPIO GPIOB


#define CS_1_Pin  GPIO_PIN_11
#define CS_2_Pin  GPIO_PIN_12
#define CS_3_Pin  GPIO_PIN_14
#define CS_4_Pin  GPIO_PIN_15

#define JUST_PIN(A)    A<0 ? GPIO_PIN_SET:GPIO_PIN_RESET  

#define CS_1  HAL_GPIO_WritePin(CS_1_GPIO,CS_1_Pin,JUST_PIN(Machine_chassis.motor[0].direction))
#define CS_2  HAL_GPIO_WritePin(CS_2_GPIO,CS_2_Pin,JUST_PIN(Machine_chassis.motor[1].direction))
#define CS_3  HAL_GPIO_WritePin(CS_3_GPIO,CS_3_Pin,JUST_PIN(Machine_chassis.motor[2].direction))
#define CS_4  HAL_GPIO_WritePin(CS_4_GPIO,CS_4_Pin,JUST_PIN(Machine_chassis.motor[3].direction))

#define DIRE(A)   (A<0 ? -1:1)    //大于0返回1，小于0返回-1


typedef struct
{
		int8_t  direction;   //正转为+，反转为-       
    int16_t speed;       //编码器检测速度
    uint16_t current;     //输出电流
} Motor_t;

typedef struct
{
	int16_t moto_x;       
	int16_t moto_y;
	int16_t moto_yaw;
	Motor_t  motor[4];
}Machine_chassis_t;
	
void MOTO_RUN(Machine_chassis_t *var1);
void MC_Solving(Machine_chassis_t *Machine_chassis);
#endif