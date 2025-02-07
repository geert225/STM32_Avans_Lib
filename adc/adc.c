/*
 * adc.c
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#include "adc.h"
#include "../registers/adc.h"

void adc_disable(){
	//ADC_CR |= BIT(1);
	ADC_CR &= ~BIT(0);
}

void adc_enable(){
	ADC_CR |= BIT(0);
}

bool adc_ready(){
	return (ADC_ISR & BIT(0));
}

bool adc_enabled(){
	return (ADC_CR & BIT(0));
}

void adc_calibrate(){
	if(adc_enabled()) adc_disable();
	ADC_CR |= BIT(31); //start calibation
	while(ADC_CR & BIT(31)); //wait for completion
}

void adc_setup_single_channel_single_capture(uint32_t channel){
	ADC_CFGR1 &= ~BIT(13); //single capture mode with simple conversion mode
	ADC_CHSELR = channel;
}

uint16_t adc_start_read(){
	ADC_CR |= BIT(2);//ADC start read
	while(!(ADC_ISR & BIT(3))); //wait until end of sequence
	return (uint16_t)(ADC_DR);
}
