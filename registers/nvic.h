/*
 * nvic.h
 *
 *  Created on: 8 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_NVIC_H_
#define REGISTERS_NVIC_H_

#include "reg.h"

#define NVIC_BASE_ADDR (0xE000E100)
#define NVIC_IPR_BASE_ADDR (0xE000E400)

#define NVIC_ISER REG(NVIC_BASE_ADDR + 0x00) //Interrupt set-enable register 
#define NVIC_ICER REG(NVIC_BASE_ADDR + 0x80) //Interrupt clear-enable register
#define NVIC_ISPR REG(NVIC_BASE_ADDR + 0x100) //Interrupt set-pending register
#define NVIC_ICPR REG(NVIC_BASE_ADDR + 0x180) //Interrupt clear-pending register

#define NVIC_IPR0 REG(NVIC_IPR_BASE_ADDR + 0x00) //Interrupt priority register 0
#define NVIC_IPR1 REG(NVIC_IPR_BASE_ADDR + 0x04) //Interrupt priority register 1
#define NVIC_IPR2 REG(NVIC_IPR_BASE_ADDR + 0x08) //Interrupt priority register 2
#define NVIC_IPR3 REG(NVIC_IPR_BASE_ADDR + 0x0c) //Interrupt priority register 3
#define NVIC_IPR4 REG(NVIC_IPR_BASE_ADDR + 0x10) //Interrupt priority register 4
#define NVIC_IPR5 REG(NVIC_IPR_BASE_ADDR + 0x14) //Interrupt priority register 5
#define NVIC_IPR6 REG(NVIC_IPR_BASE_ADDR + 0x18) //Interrupt priority register 6
#define NVIC_IPR7 REG(NVIC_IPR_BASE_ADDR + 0x1c) //Interrupt priority register 7

#endif /* REGISTERS_NVIC_H_ */
