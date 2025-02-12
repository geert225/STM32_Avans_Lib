/*
 * simpel_timer.h
 *
 *  Created on: 12 feb. 2025
 *      Author: geert
 */

#ifndef TIMER_SIMPEL_TIMER_SIMPEL_TIMER_H_
#define TIMER_SIMPEL_TIMER_SIMPEL_TIMER_H_

#include "../../registers/timer.h"

typedef enum {
	SIMPEL_TIMER_6 = TIM6_BASE_ADDR,
	SIMPEL_TIMER_7 = TIM7_BASE_ADDR
} simpel_timer_t;

void simpel_timer_setup(register_t timer, uint16_t preScaller, uint16_t autoReload);

bool simpel_timer_interrupt_pending(register_t timer);
void simpel_timer_interrupt_acknolede(register_t timer);

void simpel_timer_enable(register_t timer);
void simpel_timer_disable(register_t timer);

#endif /* TIMER_SIMPEL_TIMER_SIMPEL_TIMER_H_ */
