/*
 * gpio.h
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

#include "../common.h"
#include "../registers/gpio.h"

typedef enum {
    GPIO_PORT_A = GPIOA_BASE_ADDR,
    GPIO_PORT_B = GPIOB_BASE_ADDR,
    GPIO_PORT_C = GPIOC_BASE_ADDR,
    GPIO_PORT_D = GPIOD_BASE_ADDR,
    GPIO_PORT_E = GPIOE_BASE_ADDR,
    GPIO_PORT_F = GPIOF_BASE_ADDR
} gpio_ports_t;

typedef enum {
    GPIO_PIN_0 = BIT(0),
    GPIO_PIN_1 = BIT(1),
    GPIO_PIN_2 = BIT(2),
    GPIO_PIN_3 = BIT(3),
    GPIO_PIN_4 = BIT(4),
    GPIO_PIN_5 = BIT(5),
    GPIO_PIN_6 = BIT(6),
    GPIO_PIN_7 = BIT(7),
    GPIO_PIN_8 = BIT(8),
    GPIO_PIN_9 = BIT(9),
    GPIO_PIN_10 = BIT(10),
    GPIO_PIN_11 = BIT(11),
    GPIO_PIN_12 = BIT(12),
    GPIO_PIN_13 = BIT(13),
    GPIO_PIN_14 = BIT(14),
    GPIO_PIN_15 = BIT(15)
} gpio_pins_t;

typedef enum {
	GPIO_MODE_INPUT = 0,
	GPIO_MODE_OUTPUT = 1,
	GPIO_MODE_ALTERNATE_FUNCTION = 2,
	GPIO_MODE_ANALOG = 3
} gpio_modes_t;

typedef enum {
    GPIO_OUTPUT_TYPE_PUSH_PULL = 0,
    GPIO_OUTPUT_TYPE_OPEN_DRAIN = 1,
	GPIO_OUTPUT_TYPE_DEFAULT = 0
} gpio_output_type_t;

typedef enum {
    GPIO_OUTPUT_SPEED_LOW = 0,
    GPIO_OUTPUT_SPEED_MEDIUM = 1,
    GPIO_OUTPUT_SPEED_HIGH = 3,
	GPIO_OUTPUT_SPEED_DEFAULT = 1
} gpio_output_speed_t;

typedef enum {
    GPIO_INPUT_TYPE_NORMAL = 0,
    GPIO_INPUT_TYPE_PULLUP = 1,
    GPIO_INPUT_TYPE_PULLDOWN = 2
} gpio_input_type_t;

typedef enum {
    GPIO_AF0 = 0,
    GPIO_AF1 = 1,
    GPIO_AF2 = 2,
    GPIO_AF3 = 3,
    GPIO_AF4 = 4,
    GPIO_AF5 = 5,
    GPIO_AF6 = 6,
    GPIO_AF7 = 7
} gpio_alternate_function_t;

void gpio_set_mode(stm_register_t port, uint16_t pins, gpio_modes_t mode);
void gpio_set_input_settings(stm_register_t port, uint16_t pins, gpio_input_type_t type);
void gpio_set_output_settings(stm_register_t port, uint16_t pins, gpio_output_type_t type, gpio_output_speed_t speed);
void gpio_set_alternate_function(stm_register_t port, uint16_t pins, gpio_alternate_function_t function);
/*
uint16_t gpio_read(register_t port, uint16_t pins);
void gpio_write(register_t port, uint16_t pins, bool value);
void gpio_set(register_t port, uint16_t pins);
void gpio_reset(register_t port, uint16_t pins);
void gpio_toggle(register_t port, uint16_t pins);
*/

//static inline function will be optimezed if -O3 is selected to inline function calls (local copy)
static inline uint16_t gpio_read(stm_register_t port, uint16_t pins){
	return(REG(port + GPIOx_IDR) & pins);
}

static inline void gpio_write(stm_register_t port, uint16_t pins, bool value){
	BITS_WRITE(REG(port + GPIOx_ODR), pins, value);
}

static inline void gpio_set(stm_register_t port, uint16_t pins){
	BITS_SET(REG(port + GPIOx_ODR), pins);
}

static inline void gpio_reset(stm_register_t port, uint16_t pins){
	BITS_RESET(REG(port + GPIOx_ODR), pins);
}

static inline void gpio_toggle(stm_register_t port, uint16_t pins){
	BITS_TOGGLE(REG(port + GPIOx_ODR), pins);
}

#endif /* GPIO_GPIO_H_ */
