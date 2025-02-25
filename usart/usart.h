/*
 * usart.h
 *
 *  Created on: 25 feb. 2025
 *      Author: geert
 */

#ifndef USART_USART_H_
#define USART_USART_H_

#include "../common.h"
#include "../registers/usart.h"

typedef enum {
    USART_1 = USART1_BASE_ADDR,
	USART_2 = USART2_BASE_ADDR,
	USART_3 = USART3_BASE_ADDR,
	USART_4 = USART4_BASE_ADDR,
	USART_5 = USART5_BASE_ADDR,
	USART_6 = USART6_BASE_ADDR,
	USART_7 = USART7_BASE_ADDR,
	USART_8 = USART8_BASE_ADDR
} usart_t;

typedef enum {
    USART_MODE_RX = BIT(2),
	USART_MODE_TX = BIT(3),
	USART_MODE_RX_TX = (BIT(2) | BIT(3))
} usart_mode_t;

typedef enum {
    USART_STOP_BITS_0_5 = (0x01 << 12),
	USART_STOP_BITS_1 = (0x00 << 12),
	USART_STOP_BITS_1_5 = (0x03 << 12),
	USART_STOP_BITS_2 = (0x02 << 12)
} usart_stop_bits_t;

typedef enum {
    USART_PARITY_NONE = 0,
	USART_PARITY_ODD = (BIT(10) | BIT(9)),
	USART_PARITY_EVEN = BIT(10)
} usart_parity_t;

typedef enum {
    USART_FLOW_CONTROL_NONE = 0,
	USART_FLOW_CONTROL_RTS = BIT(8),
	USART_FLOW_CONTROL_CTS = BIT(9),
	USART_FLOW_CONTROL_RTS_CTS = (BIT(8) | BIT(9))
} usart_flow_control_t;

void usart_enable(stm_register_t usart);
void usart_disable(stm_register_t usart);

void usart_set_mode(stm_register_t usart, usart_mode_t mode);
void usart_set_baudrate(stm_register_t usart, int baudrate);
void usart_set_parity(stm_register_t usart, usart_parity_t parity);
void usart_set_data_bits(stm_register_t usart, uint8_t bits); // includes the parity bit
void usart_set_stop_bits(stm_register_t usart, usart_stop_bits_t stopBits);
void usart_set_flow_control(stm_register_t usart, usart_flow_control_t flowControl);
void usart_send(stm_register_t usart, uint8_t data);

#endif /* USART_USART_H_ */
