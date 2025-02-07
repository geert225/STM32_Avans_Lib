/*
 * display.c
 *
 *  Created on: 6 feb. 2025
 *      Author: geert
 */

#include "display.h"
#include "../../gpio/gpio.h"

#define DISPLAY_PORT GPIO_PORT_A
#define DISPLAY_CLK_PIN GPIO_PIN_5
#define DISPLAY_DIO_PIN GPIO_PIN_6

#define DISPLAY_DELAY 60

static bool displayon = false; //default display off
static uint8_t displayBrightness = 7; //default max brigthness
static bool displayDot = false;
static uint8_t displayData[4] = {0}; //default empty

static void display_send(uint8_t data){
	//bits
	for (int i = 0; i < 8; ++i) {
		gpio_reset(DISPLAY_PORT, DISPLAY_CLK_PIN);
		gpio_write(DISPLAY_PORT, DISPLAY_DIO_PIN, (data) & 1);
		gpio_set(DISPLAY_PORT, DISPLAY_CLK_PIN);
		core_clock_delay_cycles(DISPLAY_DELAY);
		gpio_reset(DISPLAY_PORT, DISPLAY_CLK_PIN);
		core_clock_delay_cycles(DISPLAY_DELAY);
		data = data >> 1;
	}
	//ack
	gpio_reset(DISPLAY_PORT, DISPLAY_CLK_PIN | DISPLAY_DIO_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
	gpio_set(DISPLAY_PORT, DISPLAY_CLK_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
	gpio_reset(DISPLAY_PORT, DISPLAY_CLK_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
}

static void display_start(){
	//start
	gpio_set(DISPLAY_PORT, DISPLAY_CLK_PIN | DISPLAY_DIO_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
	gpio_reset(DISPLAY_PORT, DISPLAY_DIO_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
	gpio_reset(DISPLAY_PORT, DISPLAY_CLK_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
}

static void display_stop(){
	//stop
	gpio_reset(DISPLAY_PORT, DISPLAY_CLK_PIN | DISPLAY_DIO_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
	gpio_set(DISPLAY_PORT, DISPLAY_CLK_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
	gpio_set(DISPLAY_PORT, DISPLAY_DIO_PIN);
	core_clock_delay_cycles(DISPLAY_DELAY);
}

static void display_update_settings(){
	display_start();
	display_send(0x80 | (displayon << 3) | (displayBrightness & 7));
	display_stop();
}

static void display_mode(bool read, bool autoAdressInc){
	display_start();
	display_send(0x40 | (autoAdressInc << 2) | (read << 1));
	display_stop();
}

void display_config(){
	display_stop();
	display_update_settings();
	display_refresh_segments();
}

void display_set_brightness(uint8_t brightness){
	brightness &= 7;
	if(displayBrightness == brightness) return;
	displayon = true;
	display_update_settings();
}

void display_on(){
	if(displayon) return;
	displayon = true;
	display_update_settings();
}

void display_off(){
	if(!displayon) return;
	displayon = false;
	display_update_settings();
}

void display_set_dot(bool on){
	if(displayDot == on) return;
	displayDot = on;
	display_mode(false, true);
	display_start();
	display_send(0xC1);
	display_send(displayData[1] | (displayDot << 7));
	display_stop();
}

void display_toggle_dot(){
	display_set_dot(!displayDot);
}

void display_set_segment(int segment, uint8_t value){
	if(segment < 0 || segment > 3) return;
	value &= 0x7f;
	displayData[segment] = value;
}

void display_refresh_segments(){
	display_mode(false, false);
	display_start();
	display_send(0xC0);
	display_send(displayData[0]);
	display_send(displayData[1] | (displayDot << 7));
	display_send(displayData[2]);
	display_send(displayData[3]);
	display_stop();
}
