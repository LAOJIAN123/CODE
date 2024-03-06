/*************************************************************************************
 * Description: 
 * Version: 
 * Author: 林志坚
 * Date: 2024-03-01 10:58:58
 * LastEditors: 林志坚
 * LastEditTime: 2024-03-02 18:07:12
 *************************************************************************************/
#ifndef __OLED_H
#define __OLED_H

#include <stdint.h>
#include "OLED_Data.h"




/*FontSize鍙傛暟鍙栧€?*/
/*姝ゅ弬鏁板€间笉浠呯敤浜庡垽鏂?锛岃€屼笖鐢ㄤ簬璁＄畻妯?鍚戝瓧绗﹀亸绉伙紝榛樿?ゅ€间负瀛椾綋鍍忕礌瀹藉害*/
#define OLED_8X16				8
#define OLED_6X8				6

/*IsFilled鍙傛暟鏁板€?*/
#define OLED_UNFILLED			0
#define OLED_FILLED				1

/*********************鍙傛暟瀹忓畾涔?*/

extern uint8_t OLED_DisplayBuf[8][128];

/*鍑芥暟澹版槑*********************/

/*鍒濆?嬪寲鍑芥暟*/
void OLED_Init(void);

/*鏇存柊鍑芥暟*/
void OLED_Update(void);
void OLED_UpdateArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);

/*鏄惧瓨鎺у埗鍑芥暟*/
void OLED_Clear(void);
void OLED_ClearArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);
void OLED_Reverse(void);
void OLED_ReverseArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height);

/*鏄剧ず鍑芥暟*/
void OLED_ShowChar(uint8_t X, uint8_t Y, char Char, uint8_t FontSize);
void OLED_ShowString(uint8_t X, uint8_t Y, char *String, uint8_t FontSize);
void OLED_ShowNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowSignedNum(uint8_t X, uint8_t Y, int32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowHexNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowBinNum(uint8_t X, uint8_t Y, uint32_t Number, uint8_t Length, uint8_t FontSize);
void OLED_ShowFloatNum(uint8_t X, uint8_t Y, double Number, uint8_t IntLength, uint8_t FraLength, uint8_t FontSize);
void OLED_ShowChinese(uint8_t X, uint8_t Y, char *Chinese);
void OLED_ShowImage(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, const uint8_t *Image);
void OLED_Printf(uint8_t X, uint8_t Y, uint8_t FontSize, char *format, ...);

/*缁樺浘鍑芥暟*/
void OLED_DrawPoint(uint8_t X, uint8_t Y);
uint8_t OLED_GetPoint(uint8_t X, uint8_t Y);
void OLED_DrawLine(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1);
void OLED_DrawRectangle(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, uint8_t IsFilled);
void OLED_DrawTriangle(uint8_t X0, uint8_t Y0, uint8_t X1, uint8_t Y1, uint8_t X2, uint8_t Y2, uint8_t IsFilled);
void OLED_DrawCircle(uint8_t X, uint8_t Y, uint8_t Radius, uint8_t IsFilled);
void OLED_DrawEllipse(uint8_t X, uint8_t Y, uint8_t A, uint8_t B, uint8_t IsFilled);
void OLED_DrawArc(uint8_t X, uint8_t Y, uint8_t Radius, int16_t StartAngle, int16_t EndAngle, uint8_t IsFilled);

/*********************鍑芥暟澹版槑*/
uint8_t OLED_ShowStringArea(uint8_t X, uint8_t Y, uint8_t Width, uint8_t Height, char *String, uint8_t FontSize);	//鍖哄煙鎵撳嵃;


void OLED_Rotation_C_P(int8_t CX, int8_t CY, float* PX, float* PY, int16_t Angle);	//鐐规棆杞?
void OLED_Rotation_Block(int8_t X, int8_t Y, int8_t Width, int16_t Angle);			//鍖哄潡鏃嬭浆
void bresenham_ellipse(int x0, int y0, int rx, int ry);
void ellipse_algorithm(int8_t x0, int8_t y0, int8_t a, int8_t b);



#endif


/*****************姹熷崗绉戞妧|鐗堟潈鎵€鏈?****************/
/*****************jiangxiekeji.com*****************/
