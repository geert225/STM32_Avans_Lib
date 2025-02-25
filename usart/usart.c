/*
 * usart.c
 *
 *  Created on: 25 feb. 2025
 *      Author: geert
 */

#include "./usart.h"

void usart_enable(stm_register_t usart){
	BITS_SET(REG(usart + USARTx_CR1), BIT(0));
}

void usart_disable(stm_register_t usart){
	BITS_RESET(REG(usart + USARTx_CR1), BIT(0));
}

void usart_set_mode(stm_register_t usart, usart_mode_t mode){
	REG_WRITE(REG(usart + USARTx_CR1), (BIT(2) | BIT(3)), mode);
}

void usart_set_baudrate(stm_register_t usart, int baudrate){
	uint32_t clock = rcc_get_apb1_freq();
	REG(usart + USARTx_BRR) = (clock + baudrate / 2) / baudrate;
}

void usart_set_parity(stm_register_t usart, usart_parity_t parity){
	REG_WRITE(REG(usart + USARTx_CR1), (BIT(9) | BIT(10)), parity);
}

void usart_set_data_bits(stm_register_t usart, uint8_t bits){
	if(bits == 8){
		REG_WRITE(REG(usart + USARTx_CR1), (BIT(12) | BIT(28)), 0);
	}else{
		REG_WRITE(REG(usart + USARTx_CR1), (BIT(12) | BIT(28)), BIT(12));
	}
}

void usart_set_stop_bits(stm_register_t usart, usart_stop_bits_t stopBits){
	REG_WRITE(REG(usart + USARTx_CR2), (BIT(12) | BIT(13)), stopBits);
}

void usart_set_flow_control(stm_register_t usart, usart_flow_control_t flowControl){
	REG_WRITE(REG(usart + USARTx_CR3), (BIT(8) | BIT(9)), flowControl);
}

void usart_send(stm_register_t usart, uint8_t data){
	//wait until ready
	while (!(REG(usart + USARTx_ISR) & BIT(7)));
	REG(usart + USARTx_TDR) = data;
}
