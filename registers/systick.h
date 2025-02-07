/*
 * systick.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_SYSTICK_H_
#define REGISTERS_SYSTICK_H_

#include "reg.h"

#define SYSTICK_BASE_ADDR (0xE000E010)

#define STK_CSR 	REG(SYSTICK_BASE_ADDR + 0x00) //SysTick control and status register
#define STK_RVR 	REG(SYSTICK_BASE_ADDR + 0x04) //SysTick reload value register
#define STK_CVR 	REG(SYSTICK_BASE_ADDR + 0x08) //SysTick current value register
#define STK_CALIB 	REG(SYSTICK_BASE_ADDR + 0x0C) //SysTick calibration value register

#endif /* REGISTERS_SYSTICK_H_ */
