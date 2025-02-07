/*
 * rcc.h
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#ifndef RCC_RCC_H_
#define RCC_RCC_H_

#include "../common.h"

typedef enum {
    RCC_AHB_DMA = BIT(0),
    RCC_AHB_DMA1 = BIT(0),
    RCC_AHB_DMA2 = BIT(1),
    RCC_AHB_SRAM = BIT(2),
    RCC_AHB_FLTIF = BIT(4),
    RCC_AHB_CRC = BIT(6),
    RCC_AHB_GPIOA = BIT(17),
    RCC_AHB_GPIOB = BIT(18),
    RCC_AHB_GPIOC = BIT(19),
    RCC_AHB_GPIOD = BIT(20),
    RCC_AHB_GPIOE = BIT(21),
    RCC_AHB_GPIOF = BIT(22),
    RCC_AHB_TSC = BIT(24)
} rcc_ahb_clken_t;

typedef enum {
    RCC_APB2_SYSCFG = BIT(0),
    RCC_APB2_COMP = BIT(0),
    RCC_APB2_USART6 = BIT(5),
    RCC_APB2_USART7 = BIT(6),
    RCC_APB2_USART8 = BIT(7),
    RCC_APB2_ADC = BIT(9),
    RCC_APB2_ADC1 = BIT(9),
    RCC_APB2_TIM1 = BIT(11),
    RCC_APB2_SPI1 = BIT(12),
    RCC_APB2_USART1 = BIT(14),
    RCC_APB2_TIM15 = BIT(16),
    RCC_APB2_TIM16 = BIT(17),
    RCC_APB2_TIM17 = BIT(18),
    RCC_APB2_DBGMCU = BIT(22),
} rcc_apb2_clken_t;

typedef enum {
    RCC_APB1_TIM2 = BIT(0),
    RCC_APB1_TIM3 = BIT(1),
    RCC_APB1_TIM6 = BIT(4),
    RCC_APB1_TIM7 = BIT(5),
    RCC_APB1_TIM14 = BIT(8),
    RCC_APB1_WWDG = BIT(11),
    RCC_APB1_SPI2 = BIT(14),
    RCC_APB1_USART2 = BIT(17),
    RCC_APB1_USART3 = BIT(18),
    RCC_APB1_USART4 = BIT(19),
    RCC_APB1_USART5 = BIT(20),
    RCC_APB1_I2C1 = BIT(21),
    RCC_APB1_I2C2 = BIT(22),
    RCC_APB1_USB = BIT(23),
    RCC_APB1_CAN = BIT(25),
    RCC_APB1_CAN1 = BIT(25),
    RCC_APB1_CRS = BIT(27),
    RCC_APB1_PWR = BIT(28),
    RCC_APB1_DAC = BIT(29),
    RCC_APB1_DAC1 = BIT(29),
    RCC_APB1_CEC = BIT(30),
} rcc_apb1_clken_t;

void rcc_ahb_clock_enable(uint32_t clken);
void rcc_ahb_clock_disable(uint32_t clken);

void rcc_apb2_clock_enable(uint32_t clken);
void rcc_apb2_clock_disable(uint32_t clken);

void rcc_apb1_clock_enable(uint32_t clken);
void rcc_apb1_clock_disable(uint32_t clken);

#endif /* RCC_RCC_H_ */
