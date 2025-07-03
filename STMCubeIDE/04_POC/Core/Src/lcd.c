/*
 * lcd.c
 *
 *  Created on: Jul 3, 2025
 *      Author: Tanishq
 */


#include "lcd.h"
#include "stm32f4xx_hal.h"

#define LCD_BACKLIGHT 0x08
#define ENABLE 0x04

void LCD_Send_Cmd(I2C_HandleTypeDef *hi2c, char cmd)
{
  char data_u, data_l;
  uint8_t data_t[4];
  data_u = (cmd & 0xF0);
  data_l = ((cmd << 4) & 0xF0);
  data_t[0] = data_u | LCD_BACKLIGHT | ENABLE;
  data_t[1] = data_u | LCD_BACKLIGHT;
  data_t[2] = data_l | LCD_BACKLIGHT | ENABLE;
  data_t[3] = data_l | LCD_BACKLIGHT;
  HAL_I2C_Master_Transmit(hi2c, LCD_ADDR, data_t, 4, 100);
}

void LCD_Send_Data(I2C_HandleTypeDef *hi2c, char data)
{
  char data_u, data_l;
  uint8_t data_t[4];
  data_u = (data & 0xF0);
  data_l = ((data << 4) & 0xF0);
  data_t[0] = data_u | LCD_BACKLIGHT | ENABLE | 0x01;
  data_t[1] = data_u | LCD_BACKLIGHT | 0x01;
  data_t[2] = data_l | LCD_BACKLIGHT | ENABLE | 0x01;
  data_t[3] = data_l | LCD_BACKLIGHT | 0x01;
  HAL_I2C_Master_Transmit(hi2c, LCD_ADDR, data_t, 4, 100);
}

void LCD_Init(I2C_HandleTypeDef *hi2c)
{
  HAL_Delay(50);
  LCD_Send_Cmd(hi2c, 0x30);
  HAL_Delay(5);
  LCD_Send_Cmd(hi2c, 0x30);
  HAL_Delay(1);
  LCD_Send_Cmd(hi2c, 0x30);
  HAL_Delay(10);
  LCD_Send_Cmd(hi2c, 0x20); // 4-bit mode
  HAL_Delay(10);

  LCD_Send_Cmd(hi2c, 0x28); // 4-bit, 2 line
  HAL_Delay(1);
  LCD_Send_Cmd(hi2c, 0x08); // Display OFF
  HAL_Delay(1);
  LCD_Send_Cmd(hi2c, 0x01); // Clear
  HAL_Delay(2);
  LCD_Send_Cmd(hi2c, 0x06); // Entry mode
  HAL_Delay(1);
  LCD_Send_Cmd(hi2c, 0x0C); // Display ON, cursor OFF
}

void LCD_Send_String(I2C_HandleTypeDef *hi2c, char *str)
{
  while (*str) LCD_Send_Data(hi2c, *str++);
}

void LCD_Clear(I2C_HandleTypeDef *hi2c)
{
  LCD_Send_Cmd(hi2c, 0x01);
  HAL_Delay(2);
}

void LCD_Set_Cursor(I2C_HandleTypeDef *hi2c, uint8_t row, uint8_t col)
{
  uint8_t pos = (row == 1) ? (0x80 + col) : (0xC0 + col);
  LCD_Send_Cmd(hi2c, pos);
}
