/*
 * clock.c
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#include "../core/clock.h"

#include "../registers/systick.h"

volatile static time_t ticks = 0;

//systick interrupt
void SysTick_Handler(){
	ticks++;
}

void core_clock_config(){
	STK_CVR = 0; // clear counter
	STK_RVR = (8000 - 1); //8mhz / 1000 = 8000 ticks per 1ms
	STK_CSR |= BIT(2) | BIT(1) | BIT(0); //enable systick (bit 0), enable ISR (bit 1), use processor clock (bit 2)
}

void core_clock_delay(time_t time){
	time_t start = ticks;
	while((start + time) > ticks);
}

time_t core_clock_get_time(){
	return ticks;
}

void core_clock_delay_cycles(int cycles){
	int i;
	for (i = 0; i < cycles; ++i) {
		asm volatile("nop");
	}
}
