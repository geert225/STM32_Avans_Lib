/*
 * console.h
 *
 *  Created on: 10 feb. 2025
 *      Author: geert
 */

#ifndef CORE_CONSOLE_H_
#define CORE_CONSOLE_H_

#include <stdio.h>

#define core_console_log(...) printf(__VA_ARGS__)

void core_console_config();

#endif /* CORE_CONSOLE_H_ */
