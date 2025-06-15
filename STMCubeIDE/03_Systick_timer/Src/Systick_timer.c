/*
 * Systick_timer.c
 *
 *  Created on: Jun 15, 2025
 *      Author: Tanishq
 */

#include "Systick_timer.h"
#include "GPIO_Driver.h"
void Systick_init()
{
//	__disable_irq();
	SysTick_CRTL &=0;
	SysTick_LOAD |= 0x00FFFFFF;
	SysTick_VAL &= 0;
	SysTick_CRTL |= 0x5;
//	__enable_irq();
}

void Delay_Mills()
{
	int cycles = 18 * 1000;
	SysTick_LOAD &= 0x0;
	SysTick_LOAD |= cycles - 1;; //Puting load value to AHB
	SysTick_VAL &= 0; //current counter to zero
	while(!(SysTick_CRTL & 0x10000));


}

//User input delay
void Systick_DelayMs(unsigned int t)
{
	while(t--)
	{
		Delay_Mills();
	}
}


//void TIM2_IRQHandler(void) {
//    if (TIM2_SR & 1) {         // Check UIF flag
//        TIM2_SR &= ~1;         // Clear UIF
//
//        // Toggle PA5
//        GPIOA_ODR ^= (1 << 5);
//    }
//}
//
//void timer2_init(void) {
//    RCC_APB1ENR |= (1 << 0);   // Enable TIM2 clock
//
//    TIM2_PSC = 16000 - 1;      // Prescaler
//    TIM2_ARR = 1000 - 1;       // Auto-reload
//
//    TIM2_DIER |= 1;            // Enable update interrupt
//    TIM2_CR1 |= 1;             // Enable counter
//
//    NVIC_ISER0 |= (1 << 28);   // Enable TIM2 IRQ (IRQ #28)
//}


