/*
 * adc.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_ADC_H_
#define REGISTERS_ADC_H_

#include "reg.h"

#define ADC_BASE_ADDR (0x40012400)

/* address offset for specific adc registers*/
#define ADC_ISR 	REG(ADC_BASE_ADDR + 0x00) //ADC interrupt and status register
#define ADC_IER 	REG(ADC_BASE_ADDR + 0x04) //ADC interrupt enable register
#define ADC_CR 		REG(ADC_BASE_ADDR + 0x08) //ADC control register
#define ADC_CFGR1 	REG(ADC_BASE_ADDR + 0x0c) //ADC configuration register 1
#define ADC_CFGR2 	REG(ADC_BASE_ADDR + 0x10) //ADC configuration register 2
#define ADC_SMPR 	REG(ADC_BASE_ADDR + 0x14) //ADC sampling time register
#define ADC_TR 		REG(ADC_BASE_ADDR + 0x20) //ADC watchdog threshold register
#define ADC_CHSELR 	REG(ADC_BASE_ADDR + 0x28) //ADC channel selection register
#define ADC_DR 		REG(ADC_BASE_ADDR + 0x40) //ADC data register
#define ADC_CCR 	REG(ADC_BASE_ADDR + 0x308) //ADC common configuration register

#endif /* REGISTERS_ADC_H_ */
