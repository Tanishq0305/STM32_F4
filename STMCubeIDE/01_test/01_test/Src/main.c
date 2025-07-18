/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

/**
******************************************************************************
* @file           : main.c
* @author         : Auto-generated by STM32CubeIDE
* @brief          : Main program body
******************************************************************************
* @attention
*
* Copyright (c) 2025 STMicroelectronics.
* All rights reserved.
*
* This software is licensed under terms that can be found in the LICENSE file
* in the root directory of this software component.
* If no LICENSE file comes with this software, it is provided AS-IS.
*
******************************************************************************
*/

#include <stdint.h>
#include "GPIO_Driver.h"


int main(void)
{
    RCC->AHB1ENR |= (1 << 0);
//	init_GP(PA,2,OUT,O_PP,O_HS);
//	RCC_AHBH1 |= (1 << 0);
    GPIOA->MODER &= 0xFFFFF0FF;
    GPIOA->MODER |= 0x10;
    GPIOA->OTYPER &= ~(1<<2);
//    GPIOA->OSPEEDER |= 0x2;

    GPIOA->OSPEEDER &= ~(3 << (2 * 2)); // Clear speed bits
    GPIOA->OSPEEDER |= (2 << (2 * 2)); // Set high speed

    GPIOA->ODR |= 0x4;
    while(1);

}

