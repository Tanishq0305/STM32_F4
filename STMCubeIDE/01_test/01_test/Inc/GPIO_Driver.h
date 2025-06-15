/*
* GPIO_Driver.h
*
*  Created on: June 01, 2025
*      Author: Tanishq
*/

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_


#include "stm32f446re.h"

#define RCC_AHBH1 (*((volatile unsigned long *) 0x40023830 ))

#define GPIOAa (*((volatile unsigned long *) 0x40020000 ))
//#define GPIOB (*((volatile unsigned long *) 0x40020400 ))
//#define GPIOC (*((volatile unsigned long *) 0x40020800 ))

void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt,unsigned short speed);

//Ports
#define PA 1
#define PB 2
#define PC 3

//Directions
#define IN 0
#define OUT 1
#define AF 2
#define AM 3

//Directions for Output
#define O_PP 0
#define O_OD 1

//Output speed
#define O_LS 0
#define O_MS 1
#define O_FS 2
#define O_HS 3

//GPIO port Pull up Pull down
#define NPP 0
#define PU 1
#define PD 2
#define RES 3

#define GPIOx(in) #in;

#endif /* GPIO_DRIVER_H_ */
