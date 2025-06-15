/*
 * GPIO_Driver.h
 *
 *  Created on: Jun 15, 2025
 *      Author: Tanishq
 */

#include <stdint.h>
#include "GPIO_Driver.h"

int main(void)
{
	init_GP(PA, 5, OUT, O_PP, O_FS);

	while(1)
	{
		GPIO_Write(PA, 5, 1);
	}
}
