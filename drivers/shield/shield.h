/*
 * shield.h
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#ifndef DRIVERS_SHIELD_SHIELD_H_
#define DRIVERS_SHIELD_SHIELD_H_

#include "../../common.h"

void shield_config();
void adc_config();
void led_write(int num, int on);
int button_read();
uint16_t potentiometer_read();

#endif /* DRIVERS_SHIELD_SHIELD_H_ */
