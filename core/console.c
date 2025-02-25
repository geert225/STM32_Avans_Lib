/*
 * console.c
 *
 *  Created on: 10 feb. 2025
 *      Author: geert
 */

#include "console.h"
#include "../gpio/gpio.h"
#include "../rcc/rcc.h"
#include "../usart/usart.h"

static void core_console_send_bytes(uint8_t* buffer, int length){
	for (int i = 0; i < length; ++i) {
		usart_send(USART_2, buffer[i]);
	}
}

int _write(int file, char *ptr, int len)
{
	core_console_send_bytes((uint8_t*)ptr, len);
	return len;
}

int _close(int file)
{
	return -1;
}

int _fstat(int file, struct stat *st)
{
	return 0;
}

int _isatty(int file)
{
	return 1;
}

int _lseek(int file, int ptr, int dir)
{
	return 0;
}

int _read(int file, char *ptr, int len){
	return len;
}

void core_console_config(){
	//console is connected via usart x to pins PA2 & 3 to st-link debugger
	//AF1 = Usart2
	rcc_apb1_clock_enable(RCC_APB1_USART2);
	rcc_ahb_clock_enable(RCC_AHB_GPIOA);

	gpio_set_mode(GPIO_PORT_A, GPIO_PIN_2 | GPIO_PIN_3, GPIO_MODE_ALTERNATE_FUNCTION);
	gpio_set_alternate_function(GPIO_PORT_A, GPIO_PIN_2 | GPIO_PIN_3, GPIO_AF1);

	usart_set_mode(USART_2, USART_MODE_RX_TX);
	usart_set_data_bits(USART_2, 8);
	usart_set_flow_control(USART_2, USART_FLOW_CONTROL_NONE);
	usart_set_parity(USART_2, USART_PARITY_NONE);
	usart_set_stop_bits(USART_2, USART_STOP_BITS_1);
	usart_set_baudrate(USART_2, 115200);

	usart_enable(USART_2);

	printf("\n\n\n\n");
}
