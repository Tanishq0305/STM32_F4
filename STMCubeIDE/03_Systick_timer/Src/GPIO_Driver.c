/*
 * GPIO_Driver.c
 *
 *  Created on: Jun 15, 2025
 *      Author: Tanishq
 */

#include "GPIO_Driver.h"


void init_GP(unsigned short port, unsigned short pin, unsigned short dir, unsigned short opt, unsigned short speed)

{
			RCC_AHBH1 |= (1<<(port-1));
			if(port==1)
			{
				GPIOAa_MODER &= ~(0x11 << pin*2);
				GPIOAa_MODER |= (dir << pin*2);
			}
			else if(port==2)
			{
				GPIOBb_MODER &= ~(0x11 << pin*2);
				GPIOBb_MODER |= (dir << pin*2);

			}
			else if(port==3)
			{
				GPIOCc_MODER &= ~(0x11 << pin*2);
				GPIOCc_MODER |= (dir << pin*2);
			}
			else if(port == 4)
			{
				GPIODd_MODER &= ~(0x11 << pin*2);
				GPIODd_MODER |= (dir << pin*2);
			}

}

void GPIO_Write(unsigned short port, unsigned short pin,unsigned short state)
{
	unsigned long * ODR;


	if(port ==1)
	{
		ODR = &GPIOAa_ODR;
	}
	else if(port == 2)
	{
		ODR = &GPIOBb_ODR;
	}
	else if(port == 3)
	{
		ODR = &GPIOCc_ODR;
	}
	else if(port == 4)
	{
		ODR = &GPIODd_ODR;
	}

//	state ? (*ODR |= (state<<pin)):(*ODR &= ~(state<<pin));
	if(state == 1)
	{
		*ODR = (1<<pin);
	}
	else
	{
		*ODR &= ~(0<<pin);
	}
}

int GPIO_Read(unsigned short port, unsigned short pin)
{
	unsigned long * IDR;
	int state;

	if(port ==1)
		{
			IDR = &GPIOAa_IDR;
		}
		else if(port == 2)
		{
			IDR = &GPIOBb_IDR;
		}
		else if(port == 3)
		{
			IDR = &GPIOCc_IDR;
		}
		else if(port ==4)
		{
			IDR = &GPIODd_IDR;
		}


	state = (*IDR & (1<<pin))?1:0;

	return state;
}

void toggle_GP(unsigned short port, unsigned short pin)
{
	if(GPIO_Read(port,pin)==1)
	{
		GPIO_Write(port,pin,0);
	}
	else
	{
		GPIO_Write(port,pin,1);
	}

}
