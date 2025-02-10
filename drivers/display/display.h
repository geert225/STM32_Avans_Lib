/*
 * display.h
 *
 *  Created on: 6 feb. 2025
 *      Author: geert
 */

#ifndef DRIVERS_DISPLAY_DISPLAY_H_
#define DRIVERS_DISPLAY_DISPLAY_H_

#include "../../common.h"

void display_config();
void display_set_brightness(uint8_t brightness);
void display_on();
void display_off();
void display_set_dot(bool on);
void display_toggle_dot();
void display_set_segment(int segment, uint8_t value);
void display_refresh_segments();


uint8_t minus_segment();
uint8_t byte_to_segment(uint8_t data);

#endif /* DRIVERS_DISPLAY_DISPLAY_H_ */
