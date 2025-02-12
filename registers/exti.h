/*
 * exti.h
 *
 *  Created on: 10 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_EXTI_H_
#define REGISTERS_EXTI_H_

#include "reg.h"

#define EXTI_BASE_ADDR (0x40010400)

/* address offset for specific adc registers*/
#define EXTI_IMR    REG(EXTI_BASE_ADDR + 0x00) //Interrupt mask register 
#define EXTI_EMR    REG(EXTI_BASE_ADDR + 0x04) //Event mask register 
#define EXTI_RTSR   REG(EXTI_BASE_ADDR + 0x08) //Rising trigger selection register
#define EXTI_FTSR   REG(EXTI_BASE_ADDR + 0x0c) //Falling trigger selection register
#define EXTI_SWIER  REG(EXTI_BASE_ADDR + 0x10) //Software interrupt event register 
#define EXTI_PR     REG(EXTI_BASE_ADDR + 0x14) //Pending register

#endif /* REGISTERS_EXTI_H_ */
