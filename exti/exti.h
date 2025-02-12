/*
 * exti.h
 *
 *  Created on: 12 feb. 2025
 *      Author: geert
 */

#ifndef EXTI_EXTI_H_
#define EXTI_EXTI_H_

#include "../common.h"

typedef enum {
	EXTI_CH0 = BIT(0),
	EXTI_CH1 = BIT(1),
	EXTI_CH2 = BIT(2),
	EXTI_CH3 = BIT(3),
	EXTI_CH4 = BIT(4),
	EXTI_CH5 = BIT(5),
	EXTI_CH6 = BIT(6),
	EXTI_CH7 = BIT(7),
	EXTI_CH8 = BIT(8),
	EXTI_CH9 = BIT(9),
	EXTI_CH10 = BIT(10),
	EXTI_CH11 = BIT(11),
	EXTI_CH12 = BIT(12),
	EXTI_CH13 = BIT(13),
	EXTI_CH14 = BIT(14),
	EXTI_CH15 = BIT(15),
	EXTI_CH_PVD = BIT(16),
	EXTI_CH_RTC_ALARM = BIT(17),
	EXTI_CH_USB_WAKE = BIT(18),
	EXTI_CH_RTC_TAMPER = BIT(19),
	EXTI_CH_RTC_TIMESTAMP = BIT(19),
	EXTI_CH_RTC_WAKE = BIT(20),
	EXTI_CH_COMP1 = BIT(21),
	EXTI_CH_COMP2 = BIT(22),
	EXTI_CH_I2C1_WAKE = BIT(23),
	EXTI_CH_USART1_WAKE = BIT(25),
	EXTI_CH_USART2_WAKE = BIT(26),
	EXTI_CH_CEC_WAKE = BIT(27),
	EXTI_CH_USART3_WAKE = BIT(28),
	EXTI_CH_COMP_VDDIO2 = BIT(31),
} exti_channel_t;

typedef enum {
	EXTI_PORT_A = 0,
	EXTI_PORT_B = 1,
	EXTI_PORT_C = 2,
	EXTI_PORT_D = 3,
	EXTI_PORT_E = 4,
	EXTI_PORT_F = 5,
} exti_port_t;

void exti_init();

bool exti_interrupt_pending(uint32_t channels);
void exti_interrupt_acknoledge(uint32_t channels);

void exti_channel_select_port(uint32_t channels, exti_port_t port);
void exti_channel_set_mode(uint32_t channels, bool fallingEdge, bool risingEdge);

void exti_interrupt_enable(uint32_t channels);
void exti_interrupt_disable(uint32_t channels);
void exti_interrupt_disable_all();

#endif /* EXTI_EXTI_H_ */
