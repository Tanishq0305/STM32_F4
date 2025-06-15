/*
 * Systick_timer.h
 *
 *  Created on: Jun 15, 2025
 *      Author: Tanishq
 */

#ifndef SYSTICK_TIMER_H_
#define SYSTICK_TIMER_H_

void Systick_init();
void Delay_Mills();
void Systick_DelayMs(unsigned int t);
void TIM2_IRQHandler(void);
void timer2_init(void);

#define SysTick_CRTL (*((unsigned long *) 0xE000E010))
#define SysTick_LOAD (*((unsigned long *) 0xE000E014))
#define SysTick_VAL (*((unsigned long *) 0xE000E018))

// TIM2
#define TIM2_BASE       0x40000000
#define TIM2_CR1        (*(volatile unsigned int*)(TIM2_BASE + 0x00))
#define TIM2_DIER       (*(volatile unsigned int*)(TIM2_BASE + 0x0C))
#define TIM2_SR         (*(volatile unsigned int*)(TIM2_BASE + 0x10))
#define TIM2_PSC        (*(volatile unsigned int*)(TIM2_BASE + 0x28))
#define TIM2_ARR        (*(volatile unsigned int*)(TIM2_BASE + 0x2C))

#endif /* SYSTICK_TIMER_H_ */
