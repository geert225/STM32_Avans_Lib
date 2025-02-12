/*
 * exti.c
 *
 *  Created on: 12 feb. 2025
 *      Author: geert
 */

#include "exti.h"
#include "../registers/exti.h"
#include "../registers/syscfg.h"
#include "../rcc/rcc.h"
#include "../nvic/nvic.h"

void exti_init(){
	rcc_apb2_clock_enable(RCC_APB2_SYSCFG);
}

bool exti_interrupt_pending(uint32_t channels){
	return (EXTI_PR & channels);
}

void exti_interrupt_acknoledge(uint32_t channels){
	BITS_SET(EXTI_PR, channels);
}

void exti_channel_select_port(uint32_t channels, exti_port_t port){
	for (int i = 0; i < 16; ++i) {
		if(!((channels >> i) & 1)) continue;
		int offset = (i % 4) << 2; // remainder * 4
		if(i < 4){
			SYSCFG_EXTICR1 = ((SYSCFG_EXTICR1 & ~(0x0f << offset)) | (port << offset));
		}else if(i < 8){
			SYSCFG_EXTICR2 = ((SYSCFG_EXTICR2 & ~(0x0f << offset)) | (port << offset));
		}else if(i < 12){
			SYSCFG_EXTICR3 = ((SYSCFG_EXTICR3 & ~(0x0f << offset)) | (port << offset));
		}else if(i < 16){
			SYSCFG_EXTICR4 = ((SYSCFG_EXTICR4 & ~(0x0f << offset)) | (port << offset));
		}
	}
}

void exti_channel_set_mode(uint32_t channels, bool fallingEdge, bool risingEdge){
	BITS_WRITE(EXTI_FTSR, channels, fallingEdge);
	BITS_WRITE(EXTI_RTSR, channels, risingEdge);
}

void exti_interrupt_enable(uint32_t channels){
	BITS_SET(EXTI_IMR, channels);
	if(channels & (BIT(0) | BIT(1))){
		nvic_enable_irq(NVIC_IRQ_EXTI0);
	}
	if(channels & (BIT(2) | BIT(3))){
		nvic_enable_irq(NVIC_IRQ_EXTI2);
	}
	if(channels & (0xfff0)){
		nvic_enable_irq(NVIC_IRQ_EXTI4);
	}
}

void exti_interrupt_disable(uint32_t channels){
	BITS_RESET(EXTI_IMR, channels);
	if(!(channels & (BIT(0) | BIT(1)))){
		nvic_disable_irq(NVIC_IRQ_EXTI0);
	}
	if(!(channels & (BIT(2) | BIT(3)))){
		nvic_disable_irq(NVIC_IRQ_EXTI2);
	}
	if(!(channels & (0xfff0))){
		nvic_disable_irq(NVIC_IRQ_EXTI4);
	}
}

void exti_interrupt_disable_all(){
	BITS_RESET(EXTI_IMR, 0x00ff);
	nvic_disable_irq(NVIC_IRQ_EXTI0);
	nvic_disable_irq(NVIC_IRQ_EXTI2);
	nvic_disable_irq(NVIC_IRQ_EXTI4);
}
