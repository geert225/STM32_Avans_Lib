/*
 * clock.c
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#include "../core/clock.h"

#include "../registers/systick.h"
#include "../rcc/rcc.h"

volatile static time_ms_t ticks = 0;

//systick interrupt
void SysTick_Handler(){
	ticks++;
}

void core_clock_config(){
	STK_CVR = 0; // clear counter
	STK_RVR = ((rcc_get_sys_freq() / 1000) - 1); //8mhz / 1000 = 8000 ticks per 1ms
	STK_CSR |= BIT(2) | BIT(1) | BIT(0); //enable systick (bit 0), enable ISR (bit 1), use processor clock (bit 2)
}

void core_clock_delay(time_ms_t time){
	time_ms_t start = ticks;
	while((start + time) > ticks);
}

time_ms_t core_clock_get_time(){
	return ticks;
}

void core_clock_delay_cycles(int cycles){
	int i;
	for (i = 0; i < cycles; ++i) {
		asm volatile("nop");
	}
}
