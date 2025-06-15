/*
 * GPIO_Driver.h
 *
 *  Created on: Jun 15, 2025
 *      Author: Tanishq
 */

#ifndef GPIO_DRIVER_H_
#define GPIO_DRIVER_H_

#define RCC_AHBH1 (*((volatile unsigned long *) 0x40023830 ))

#define GPIOAa_MODER (*((volatile unsigned long *) 0x40020000 ))
#define GPIOBb_MODER (*((volatile unsigned long *) 0x40020400 ))
#define GPIOCc_MODER (*((volatile unsigned long *) 0x40020800 ))
#define GPIODd_MODER (*((volatile unsigned long *) 0X40020C00 ))


#define GPIOAa_ODR (*((volatile unsigned long *) 0x40020014 ))
#define GPIOBb_ODR (*((volatile unsigned long *) 0x40020414 ))
#define GPIOCc_ODR (*((volatile unsigned long *) 0x40020814 ))
#define GPIODd_ODR (*((volatile unsigned long *) 0X40020C00 ))

#define GPIOAa_IDR (*((volatile unsigned long *) 0x40020010 ))
#define GPIOBb_IDR (*((volatile unsigned long *) 0x40020410 ))
#define GPIOCc_IDR (*((volatile unsigned long *) 0x40020810 ))
#define GPIODd_IDR (*((volatile unsigned long *) 0X40020C10 ))

void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt,unsigned short speed);
void GPIO_Write(unsigned short port, unsigned short pin,unsigned short val);
int GPIO_Read(unsigned short port, unsigned short pin);
void toggle_GP(unsigned short port, unsigned short pin);
//Ports
#define PA 1
#define PB 2
#define PC 3
#define PD 4
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
#define PDD 2
#define RES 3

#define GPIOx(in) #in;

#endif /* GPIO_DRIVER_H_ */
