#ifndef KEY_OPERATE
#define KEY_OPERATE

#include "main.h"

#define KEY_GPIO	GPIOB
#define UP   			GPIO_PIN_4
#define DOWN 			GPIO_PIN_5
#define ENTER			GPIO_PIN_6
#define BACK 			GPIO_PIN_7




void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin);

int8_t Key_Enter_Get(void);
int8_t Key_Back_Get(void);
int8_t Key_Up_Get(void);
int8_t Key_Down_Get(void);
void Key_Reset_All(void);	//清除所有按键标志
#endif
