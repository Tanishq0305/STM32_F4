/*
 * lcd.h
 *
 *  Created on: Jul 3, 2025
 *      Author: Tanishq
 */

#ifndef __LCD_H__
#define __LCD_H__

#include "stm32f4xx_hal.h"

#define LCD_ADDR (0x27 << 1) // PCF8574 default address

void LCD_Init(I2C_HandleTypeDef *hi2c);
void LCD_Send_Cmd(I2C_HandleTypeDef *hi2c, char cmd);
void LCD_Send_Data(I2C_HandleTypeDef *hi2c, char data);
void LCD_Send_String(I2C_HandleTypeDef *hi2c, char *str);
void LCD_Clear(I2C_HandleTypeDef *hi2c);
void LCD_Set_Cursor(I2C_HandleTypeDef *hi2c, uint8_t row, uint8_t col);
#endif
