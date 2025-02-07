/*
 * shield.c
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#include "shield.h"

#include "../../registers/gpio.h"
#include "../../registers/adc.h"

#include "../../rcc/rcc.h"
#include "../../gpio/gpio.h"
#include "../../adc/adc.h"

uint16_t ledToBit[4] = {
	BIT(3),
	BIT(5),
	BIT(4),
	BIT(6),
};

#define CLEAR_2_BIT(pos) (3 << (pos *2))

void shield_config(){
	rcc_ahb_clock_enable(RCC_AHB_GPIOA | RCC_AHB_GPIOB);

	gpio_set_mode(GPIO_PORT_B, GPIO_PIN_8, GPIO_MODE_INPUT);
	gpio_set_input_settings(GPIO_PORT_B, GPIO_PIN_8, GPIO_INPUT_TYPE_PULLUP);

	gpio_set_mode(GPIO_PORT_B, GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6, GPIO_MODE_OUTPUT);

	gpio_set_mode(GPIO_PORT_A, GPIO_PIN_7, GPIO_MODE_ANALOG);

	// setup PA6 & PA5 for 7 segment display com
	gpio_set_mode(GPIO_PORT_A, GPIO_PIN_5 | GPIO_PIN_6, GPIO_MODE_OUTPUT);
}

void adc_config(){
	rcc_apb2_clock_enable(RCC_APB2_ADC);
	adc_disable();
	adc_calibrate();
	adc_setup_single_channel_single_capture(ADC_CHANNEL_PA7);
	adc_enable();
	while(!adc_ready());
}

void led_write(int num, int on){
	if(num < 0 || num > 3) return; //out of range
	gpio_write(GPIO_PORT_B, ledToBit[num], on);
}

int button_read(){
	return !gpio_read(GPIO_PORT_B, GPIO_PIN_8);
}

uint16_t potentiometer_read(){
	return adc_start_read();
}
