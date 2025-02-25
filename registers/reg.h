/*
 * reg.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_REG_H_
#define REGISTERS_REG_H_

#include "../common.h"

#define REG(addr) (*(volatile stm_register_t *)(addr))
#define REG_32(addr) (*(volatile uint32_t *)(addr))
#define REG_16(addr) (*(volatile uint16_t *)(addr))
#define REG_8(addr) (*(volatile uint8_t *)(addr))

#define REG_WRITE(REG, CLEARMASK, SETMASK) REG = ((REG & ~(CLEARMASK)) | SETMASK)

#endif /* REGISTERS_REG_H_ */
