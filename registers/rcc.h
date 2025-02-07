/*
 * rcc.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_RCC_H_
#define REGISTERS_RCC_H_

#include "reg.h"

#define RCC_BASE_ADDR (0x40021000)

/* address offset for specific rcc registers*/
#define RCC_CR 			REG(RCC_BASE_ADDR + 0x00) //Clock control register
#define RCC_CFGR 		REG(RCC_BASE_ADDR + 0x04) //Clock configuration register
#define RCC_CIR 		REG(RCC_BASE_ADDR + 0x08) //Clock interrupt register
#define RCC_APB2RSTR 	REG(RCC_BASE_ADDR + 0x0c) //APB peripheral reset register 2
#define RCC_APB1RSTR 	REG(RCC_BASE_ADDR + 0x10) //APB peripheral reset register 1
#define RCC_AHBENR 		REG(RCC_BASE_ADDR + 0x14) //AHB peripheral clock enable register
#define RCC_APB2ENR 	REG(RCC_BASE_ADDR + 0x18) //APB peripheral clock enable register 2
#define RCC_APB1ENR 	REG(RCC_BASE_ADDR + 0x1c) //APB peripheral clock enable register 1
#define RCC_BDCR 		REG(RCC_BASE_ADDR + 0x20) //RTC domain control register
#define RCC_CSR 		REG(RCC_BASE_ADDR + 0x24) //Control/status register
#define RCC_AHBRSTR 	REG(RCC_BASE_ADDR + 0x28) //AHB peripheral reset register
#define RCC_CFGR2 		REG(RCC_BASE_ADDR + 0x2c) //Clock configuration register 2
#define RCC_CFGR3 		REG(RCC_BASE_ADDR + 0x30) //Clock configuration register 3
#define RCC_CR2 		REG(RCC_BASE_ADDR + 0x34) //Clock control register 2

#endif /* REGISTERS_RCC_H_ */
