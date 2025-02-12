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

typedef enum {
    RCC_OSC_HSI14,
    RCC_OSC_HSI, 
    RCC_OSC_HSE, 
    RCC_OSC_PLL, 
    RCC_OSC_LSI, 
    RCC_OSC_LSE, 
    RCC_OSC_HSI48
} rcc_osc_t;

typedef enum {
    RCC_PCLK_DIV_0 = 0,
    RCC_PCLK_DIV_2 = 0x400,
    RCC_PCLK_DIV_4 = 0x500,
    RCC_PCLK_DIV_8 = 0x600,
    RCC_PCLK_DIV_16 = 0x700
} rcc_div_ppre_clken_t;

typedef enum {
    RCC_HCLK_DIV_0 = 0,
    RCC_HCLK_DIV_2 = 0x80,
    RCC_HCLK_DIV_4 = 0x90,
    RCC_HCLK_DIV_8 = 0xa0,
    RCC_HCLK_DIV_16 = 0xb0,
    RCC_HCLK_DIV_64 = 0xc0,
    RCC_HCLK_DIV_128 = 0xd0,
    RCC_HCLK_DIV_256 = 0xe0,
    RCC_HCLK_DIV_512 = 0xf0
} rcc_div_hpre_clken_t;

void rcc_ahb_clock_enable(uint32_t clken);
void rcc_ahb_clock_disable(uint32_t clken);

void rcc_apb2_clock_enable(uint32_t clken);
void rcc_apb2_clock_disable(uint32_t clken);

void rcc_apb1_clock_enable(uint32_t clken);
void rcc_apb1_clock_disable(uint32_t clken);

void rcc_osc_enable(rcc_osc_t osc);
void rcc_osc_disable(rcc_osc_t osc);
bool rcc_osc_ready(rcc_osc_t osc);

void rcc_pll_set_clock_source(rcc_osc_t osc, bool hsiDiv2);
void rcc_pll_set_multiplier(uint32_t mul);

void rcc_ppre_set(rcc_div_ppre_clken_t ppre);
void rcc_hpre_set(rcc_div_hpre_clken_t hpre);
void rcc_prediv_set(uint32_t prediv);

void rcc_rtc_set_clock_source(rcc_osc_t osc); //TODO: functie nog niet klaar!
void rcc_rtc_clock_enable();
void rcc_rtc_clock_disable();

void rcc_system_set_clock_source(rcc_osc_t osc);

void rcc_clock_setup_hsi_48mhz();

uint64_t rcc_get_sys_freq();
uint64_t rcc_get_ahb_freq();
uint64_t rcc_get_apb1_freq();
uint64_t rcc_get_apb2_freq();

#endif /* RCC_RCC_H_ */
