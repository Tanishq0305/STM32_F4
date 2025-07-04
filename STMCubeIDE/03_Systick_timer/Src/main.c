/*
 * Systick_timer.h
 *
 *  Created on: Jun 15, 2025
 *      Author: Tanishq
 */

#include <stdint.h>
#include "GPIO_Driver.h"
#include "Systick_timer.h"


int main(void)
{
	Systick_init();
	init_GP(PA, 5, OUT, O_PP, O_FS);

	while(1)
	{
		GPIO_Write(PA, 5, 1);
		Systick_DelayMs(1000);
		GPIO_Write(PA, 5, 0);
		Systick_DelayMs(1000);
	}
}
