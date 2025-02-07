/*
 * gpio.c
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#include "gpio.h"
#include "../registers/gpio.h"

void gpio_set_mode(register_t port, uint16_t pins, gpio_modes_t mode){
    for (int i = 0; i < 16; i++)
    {
        if(!((pins >> i) & 1)) continue;
        REG(port + GPIOx_MODER) = (REG(port + GPIOx_MODER) & ~(3 << (i * 2))) | ((mode & 3) << (i * 2));
    }
}

void gpio_set_input_settings(register_t port, uint16_t pins, gpio_input_type_t type){
    for (int i = 0; i < 16; i++)
    {
    	if(!((pins >> i) & 1)) continue;
    	REG(port + GPIOx_PUPDR) = (REG(port + GPIOx_PUPDR) & ~(3 << (i * 2))) | ((type & 3) << (i * 2));
    }
}

void gpio_set_output_settings(register_t port, uint16_t pins, gpio_output_type_t type, gpio_output_speed_t speed){
    for (int i = 0; i < 16; i++)
    {
    	if(!((pins >> i) & 1)) continue;

        REG(port + GPIOx_OSPEEDR) = (REG(port + GPIOx_OSPEEDR) & ~(3 << (i * 2))) | ((speed & 3) << (i * 2));
        REG(port + GPIOx_OTYPER) = (REG(port + GPIOx_OTYPER) & ~(1 << i)) | ((type & 1) << i);
    }
}

void gpio_set_alternate_function(register_t port, uint16_t pins, gpio_alternate_function_t function){
    int offset;

    for (int i = 0; i < 8; i++)
    {
    	if(!((pins >> i) & 1)) continue;

        offset = (i * 4);
        REG(port + GPIOx_AFRL) &= ~(0x0f << offset);
        REG(port + GPIOx_AFRL) |= ((function & 0x0f) << offset);
    }

    for (int i = 0; i < 8; i++)
    {
    	if(!((pins >> (i + 8)) & 1)) continue;

        offset = (i * 4);
        REG(port + GPIOx_AFRH) &= ~(0x0f << offset);
        REG(port + GPIOx_AFRH) |= ((function & 0x0f) << offset);
    }
}

inline uint16_t gpio_read(register_t port, uint16_t pins){
	return(REG(port + GPIOx_IDR) & pins);
}

void gpio_write(register_t port, uint16_t pins, bool value){
	BITS_WRITE(REG(port + GPIOx_ODR), pins, value);
}

inline void gpio_set(register_t port, uint16_t pins){
	BITS_SET(REG(port + GPIOx_ODR), pins);
}

inline void gpio_reset(register_t port, uint16_t pins){
	BITS_RESET(REG(port + GPIOx_ODR), pins);
}

inline void gpio_toggle(register_t port, uint16_t pins){
	BITS_TOGGLE(REG(port + GPIOx_ODR), pins);
}
