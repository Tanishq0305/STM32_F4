/*
* GPIO_Driver.c
*
*  Created on: June 01, 2025
*      Author: Tanishq
*/


#include "GPIO_Driver.h"


void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt,unsigned short speed) {
	volatile unsigned long * CR;
	RCC_AHBH1 |= (1<<(port-1));
	if(port==1) {
//		GPIOAa &= 0x0;
//		GPIOA->MODER &= ~(1<<pin);
//		GPIOAa |= dir<<(pin*2);
		GPIOAa |= 0x10;
//		GPIOA->ODR |= (1<<pin);
//		(GPIOAa + 0x14) |= 0x4;

	}

}
