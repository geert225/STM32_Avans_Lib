/*
 * reg.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_REG_H_
#define REGISTERS_REG_H_

#include "../common.h"

#define REG(addr) (*(volatile register_t *)(addr))

#endif /* REGISTERS_REG_H_ */
