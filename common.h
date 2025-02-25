/*
 * common.h
 *
 *  Created on: 4 feb. 2025
 *      Author: geert
 */

#ifndef COMMON_H_
#define COMMON_H_

#include <stdbool.h>
#include <stdint.h>

#define BIT(n) (1 << (n))

#define BITS_SET(var, bits) var |= (bits)
#define BITS_TOGGLE(var, bits) var ^= (bits)
#define BITS_RESET(var, bits) var &= ~(bits)

#define BITS_WRITE(var, bits, value) (value) ? (BITS_SET(var, bits)) : (BITS_RESET(var, bits))

typedef uint32_t stm_register_t;
typedef uint64_t time_ms_t;

#endif /* COMMON_H_ */
