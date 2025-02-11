/*
 * syscfg.h
 *
 *  Created on: 10 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_SYSCFG_H_
#define REGISTERS_SYSCFG_H_

#include "reg.h"

#define SYSCFG_BASE_ADDR (0x40010000)

/* address offset for specific adc registers*/
#define SYSCFG_CFGR1 	    REG(SYSCFG_BASE_ADDR + 0x00) //configuration register 1
#define SYSCFG_EXTICR1 	    REG(SYSCFG_BASE_ADDR + 0x08) //external interrupt configuration register 1
#define SYSCFG_EXTICR2 	    REG(SYSCFG_BASE_ADDR + 0x0c) //external interrupt configuration register 2
#define SYSCFG_EXTICR3 	    REG(SYSCFG_BASE_ADDR + 0x10) //external interrupt configuration register 3
#define SYSCFG_EXTICR4 	    REG(SYSCFG_BASE_ADDR + 0x14) //external interrupt configuration register 4
#define SYSCFG_CFGR2 	    REG(SYSCFG_BASE_ADDR + 0x18) //configuration register 2

#define SYSCFG_ITLINE0 	    REG(SYSCFG_BASE_ADDR + 0x80) //interrupt line 0 status register
#define SYSCFG_ITLINE1 	    REG(SYSCFG_BASE_ADDR + 0x84) //interrupt line 1 status register
#define SYSCFG_ITLINE2 	    REG(SYSCFG_BASE_ADDR + 0x88) //interrupt line 2 status register
#define SYSCFG_ITLINE3 	    REG(SYSCFG_BASE_ADDR + 0x8c) //interrupt line 3 status register
#define SYSCFG_ITLINE4 	    REG(SYSCFG_BASE_ADDR + 0x90) //interrupt line 4 status register
#define SYSCFG_ITLINE5 	    REG(SYSCFG_BASE_ADDR + 0x94) //interrupt line 5 status register
#define SYSCFG_ITLINE6 	    REG(SYSCFG_BASE_ADDR + 0x98) //interrupt line 6 status register
#define SYSCFG_ITLINE7 	    REG(SYSCFG_BASE_ADDR + 0x9c) //interrupt line 7 status register
#define SYSCFG_ITLINE8 	    REG(SYSCFG_BASE_ADDR + 0xa0) //interrupt line 8 status register
#define SYSCFG_ITLINE9 	    REG(SYSCFG_BASE_ADDR + 0xa4) //interrupt line 9 status register
#define SYSCFG_ITLINE10     REG(SYSCFG_BASE_ADDR + 0xa8) //interrupt line 10 status register
#define SYSCFG_ITLINE11     REG(SYSCFG_BASE_ADDR + 0xac) //interrupt line 11 status register
#define SYSCFG_ITLINE12     REG(SYSCFG_BASE_ADDR + 0xb0) //interrupt line 12 status register
#define SYSCFG_ITLINE13     REG(SYSCFG_BASE_ADDR + 0xb4) //interrupt line 13 status register
#define SYSCFG_ITLINE14     REG(SYSCFG_BASE_ADDR + 0xb8) //interrupt line 14 status register
#define SYSCFG_ITLINE15     REG(SYSCFG_BASE_ADDR + 0xbc) //interrupt line 15 status register
#define SYSCFG_ITLINE16     REG(SYSCFG_BASE_ADDR + 0xc0) //interrupt line 16 status register
#define SYSCFG_ITLINE17     REG(SYSCFG_BASE_ADDR + 0xc4) //interrupt line 17 status register
#define SYSCFG_ITLINE18     REG(SYSCFG_BASE_ADDR + 0xc8) //interrupt line 18 status register
#define SYSCFG_ITLINE19     REG(SYSCFG_BASE_ADDR + 0xcc) //interrupt line 19 status register
#define SYSCFG_ITLINE20     REG(SYSCFG_BASE_ADDR + 0xd0) //interrupt line 20 status register
#define SYSCFG_ITLINE21     REG(SYSCFG_BASE_ADDR + 0xd4) //interrupt line 21 status register
#define SYSCFG_ITLINE22     REG(SYSCFG_BASE_ADDR + 0xd8) //interrupt line 22 status register
#define SYSCFG_ITLINE23     REG(SYSCFG_BASE_ADDR + 0xdc) //interrupt line 23 status register
#define SYSCFG_ITLINE24     REG(SYSCFG_BASE_ADDR + 0xe0) //interrupt line 24 status register
#define SYSCFG_ITLINE25     REG(SYSCFG_BASE_ADDR + 0xe4) //interrupt line 25 status register
#define SYSCFG_ITLINE26     REG(SYSCFG_BASE_ADDR + 0xe8) //interrupt line 26 status register
#define SYSCFG_ITLINE27     REG(SYSCFG_BASE_ADDR + 0xec) //interrupt line 27 status register
#define SYSCFG_ITLINE28     REG(SYSCFG_BASE_ADDR + 0xf0) //interrupt line 28 status register
#define SYSCFG_ITLINE29     REG(SYSCFG_BASE_ADDR + 0xf4) //interrupt line 29 status register
#define SYSCFG_ITLINE30     REG(SYSCFG_BASE_ADDR + 0xf8) //interrupt line 30 status register

#endif /* REGISTERS_SYSCFG_H_ */
