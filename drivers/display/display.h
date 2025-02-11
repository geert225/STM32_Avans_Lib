/*
 * display.h
 *
 *  Created on: 6 feb. 2025
 *      Author: geert
 */

#ifndef DRIVERS_DISPLAY_DISPLAY_H_
#define DRIVERS_DISPLAY_DISPLAY_H_

#include "../../common.h"


#define DISPLAY_SYMBOL_0 0x3f
#define DISPLAY_SYMBOL_1 0x06
#define DISPLAY_SYMBOL_2 0x5b
#define DISPLAY_SYMBOL_3 0x4f
#define DISPLAY_SYMBOL_4 0x66
#define DISPLAY_SYMBOL_5 0x6d
#define DISPLAY_SYMBOL_6 0x7d
#define DISPLAY_SYMBOL_7 0x07
#define DISPLAY_SYMBOL_8 0x7f
#define DISPLAY_SYMBOL_9 0x6f
#define DISPLAY_SYMBOL_A 0x77
#define DISPLAY_SYMBOL_B 0x7c
#define DISPLAY_SYMBOL_C 0x58
#define DISPLAY_SYMBOL_D 0x5e
#define DISPLAY_SYMBOL_E 0x79
#define DISPLAY_SYMBOL_F 0x71
#define DISPLAY_SYMBOL_H 0x76
#define DISPLAY_SYMBOL_I 0x30
#define DISPLAY_SYMBOL_J 0x0e
#define DISPLAY_SYMBOL_L 0x38
#define DISPLAY_SYMBOL_N 0x54
#define DISPLAY_SYMBOL_O 0x5c
#define DISPLAY_SYMBOL_P 0x73
#define DISPLAY_SYMBOL_Q 0x67
#define DISPLAY_SYMBOL_R 0x50
#define DISPLAY_SYMBOL_S 0x6d
#define DISPLAY_SYMBOL_T 0x78
#define DISPLAY_SYMBOL_U 0x1c
#define DISPLAY_SYMBOL_Y 0x6e
#define DISPLAY_SYMBOL_Z 0x5b
#define DISPLAY_SYMBOL_MIN 0x40


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
