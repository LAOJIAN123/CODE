#include "key_operate.h"
#include "main.h"

struct 
{
	uint8_t Enter;	//ȷ�ϼ�
	uint8_t Back;	//���ؼ�
	uint8_t Up;		//��
	uint8_t Down;	//��
} Key;


//�����жϻص�����
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == UP)
	{
		int Delay = 2600000; while(Delay--);
		if(HAL_GPIO_ReadPin(KEY_GPIO,UP) == SET)
		{
			Key.Up = 1;
		}
	}	
	else if(GPIO_Pin == DOWN)
	{
		int Delay = 2500000; while(Delay--);
		if(HAL_GPIO_ReadPin(KEY_GPIO,DOWN) == SET)
		{
			Key.Down = 1;
		}
	}
	else if(GPIO_Pin == ENTER)
	{
		int Delay = 2500000; while(Delay--);
		if(HAL_GPIO_ReadPin(KEY_GPIO,ENTER) == SET)
		{
			Key.Enter = 1;
		}
	}
	else if(GPIO_Pin == BACK)
	{
		int Delay = 2500000; while(Delay--);
		if(HAL_GPIO_ReadPin(KEY_GPIO,BACK) == SET)
		{
			Key.Back = 1;
		}
	}
}


int8_t Key_Enter_Get(void)	//ȷ�ϼ�
{
	if(Key.Enter)
	{
		Key.Enter = 0;
		return 1;
	}
	return 0;
}

int8_t Key_Back_Get(void)	//���ؼ�
{
	if(Key.Back)
	{
		Key.Back = 0;
		return 1;
	}
	return 0;
}

int8_t Key_Up_Get(void)
{
	if(Key.Up)
	{
		Key.Up = 0;
		return 1;
	}
	return 0;
}

int8_t Key_Down_Get(void)
{
	if(Key.Down)
	{
		Key.Down = 0;
		return 1;
	}
	return 0;
}

void Key_Reset_All(void)	//������а�����־λ
{
	Key.Enter = 0;
	Key.Back = 0;
	Key.Up = 0;
	Key.Down = 0;
}
