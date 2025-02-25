/*
 * clock.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef CORE_CLOCK_H_
#define CORE_CLOCK_H_

#include "../common.h"

void core_clock_config();
void core_clock_delay(time_ms_t time);
time_ms_t core_clock_get_time();
void core_clock_delay_cycles(int cycles);

#endif /* CORE_CLOCK_H_ */
