#ifndef MOTO_CONTROL
#define MOTO_CONTROL


#include "main.h"

#define moto_ride 1  //�������



//RIGHΪ��תBACKΪ��ת
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

#define DIRE(A)   (A<0 ? -1:1)    //����0����1��С��0����-1


typedef struct
{
		int8_t  direction;   //��תΪ+����תΪ-       
    int16_t speed;       //����������ٶ�
    uint16_t current;     //�������
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