/*
 * adc.h
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "../common.h"

typedef enum {
	ADC_CHANNEL_PA0 = BIT(0),
	ADC_CHANNEL_PA1 = BIT(1),
	ADC_CHANNEL_PA2 = BIT(2),
	ADC_CHANNEL_PA3 = BIT(3),
	ADC_CHANNEL_PA4 = BIT(4),
	ADC_CHANNEL_PA5 = BIT(5),
	ADC_CHANNEL_PA6 = BIT(6),
    ADC_CHANNEL_PA7 = BIT(7),
	ADC_CHANNEL_PB0 = BIT(8),
	ADC_CHANNEL_PB1 = BIT(9),
	ADC_CHANNEL_PC0 = BIT(10),
	ADC_CHANNEL_PC1 = BIT(11),
	ADC_CHANNEL_PC2 = BIT(12),
	ADC_CHANNEL_PC3 = BIT(13),
	ADC_CHANNEL_PC4 = BIT(14),
	ADC_CHANNEL_PC5 = BIT(15),
	ADC_CHANNEL_TC = BIT(16),
	ADC_CHANNEL_VREF = BIT(17),
	ADC_CHANNEL_VBAT = BIT(18)
} adc_channel_t;

void adc_disable();
void adc_enable();

bool adc_ready();
bool adc_enabled();

void adc_calibrate();

void adc_setup_single_channel_single_capture(uint32_t channel);

uint16_t adc_start_read();

#endif /* ADC_ADC_H_ */
