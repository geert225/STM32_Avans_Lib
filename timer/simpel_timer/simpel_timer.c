/*
 * simpel_timer.c
 *
 *  Created on: 12 feb. 2025
 *      Author: geert
 */

#include "simpel_timer.h"
#include "../../registers/timer.h"
#include "../../nvic/nvic.h"
#include "../../rcc/rcc.h"
#include "../../registers/reg.h"

void simpel_timer_setup(stm_register_t timer, uint16_t preScaller, uint16_t autoReload){
	if(timer != SIMPEL_TIMER_6 && timer != SIMPEL_TIMER_7) return;
	if(timer == SIMPEL_TIMER_6) rcc_apb1_clock_enable(RCC_APB1_TIM6);
	if(timer == SIMPEL_TIMER_7) rcc_apb1_clock_enable(RCC_APB1_TIM7);

	simpel_timer_disable(timer);
	REG(timer + TIMx_PSC) = (preScaller);
	REG(timer + TIMx_ARR) = (autoReload);
	REG(timer + TIMx_DIER) |= BIT(0);
}

bool simpel_timer_interrupt_pending(stm_register_t timer){
	if(timer != SIMPEL_TIMER_6 && timer != SIMPEL_TIMER_7) return false;
	return (REG(timer + TIMx_SR) & BIT(0));
}

void simpel_timer_interrupt_acknolede(stm_register_t timer){
	if(timer != SIMPEL_TIMER_6 && timer != SIMPEL_TIMER_7) return;
	BITS_RESET(REG(timer + TIMx_SR), BIT(0));
}

void simpel_timer_enable(stm_register_t timer){
	if(timer != SIMPEL_TIMER_6 && timer != SIMPEL_TIMER_7) return;
	if(timer == SIMPEL_TIMER_6) nvic_enable_irq(NVIC_IRQ_TIM6);
	if(timer == SIMPEL_TIMER_7) nvic_enable_irq(NVIC_IRQ_TIM7);
	BITS_SET(REG(timer + TIMx_CR1), BIT(0));
}

void simpel_timer_disable(stm_register_t timer){
	if(timer != SIMPEL_TIMER_6 && timer != SIMPEL_TIMER_7) return;
	if(timer == SIMPEL_TIMER_6) nvic_disable_irq(NVIC_IRQ_TIM6);
	if(timer == SIMPEL_TIMER_7) nvic_disable_irq(NVIC_IRQ_TIM7);

	BITS_RESET(REG(timer + TIMx_CR1), BIT(0));

}
