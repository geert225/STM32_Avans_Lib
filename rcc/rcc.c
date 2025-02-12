/*
 * rcc.c
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#include "rcc.h"
#include "../registers/rcc.h"

#define RCC_DEFAULT_SYS_FREQ 8000000
#define RCC_DEFAULT_AHB_FREQ 8000000
#define RCC_DEFAULT_APB_FREQ 8000000

static volatile uint64_t rcc_sys_freq = RCC_DEFAULT_SYS_FREQ;
static volatile uint64_t rcc_ahb_freq = RCC_DEFAULT_AHB_FREQ;
static volatile uint64_t rcc_apb_freq = RCC_DEFAULT_APB_FREQ;

void rcc_ahb_clock_enable(uint32_t clken){
    RCC_AHBENR |= (clken);
}

void rcc_ahb_clock_disable(uint32_t clken){
    RCC_AHBENR &= ~(clken);
}

void rcc_apb2_clock_enable(uint32_t clken){
    RCC_APB2ENR |= (clken);
}

void rcc_apb2_clock_disable(uint32_t clken){
    RCC_APB2ENR &= ~(clken);
}

void rcc_apb1_clock_enable(uint32_t clken){
    RCC_APB1ENR |= (clken);
}

void rcc_apb1_clock_disable(uint32_t clken){
    RCC_APB1ENR &= ~(clken);
}

void rcc_clock_enable(rcc_clock_t clock){
    switch (clock) {
        case RCC_CLOCK_HSI48:
            RCC_CR2 |= BIT(16);
            break;
        case RCC_CLOCK_HSI14:
            RCC_CR2 |= BIT(0);
            break;
        case RCC_CLOCK_HSI:
            RCC_CR |= BIT(0);
            break;
        case RCC_CLOCK_HSE:
            RCC_CR |= BIT(16);
            break;
        case RCC_CLOCK_LSE:
            RCC_BDCR |= BIT(0);
            break;
        case RCC_CLOCK_LSI:
            RCC_CSR |= BIT(0);
            break;
        case RCC_CLOCK_PLL:
            RCC_CR |= BIT(24);
            break;
	}
}

void rcc_clock_disable(rcc_clock_t clock){
    switch (clock) {
        case RCC_CLOCK_HSI48:
            RCC_CR2 &= ~BIT(16);
            break;
        case RCC_CLOCK_HSI14:
            RCC_CR2 &= ~BIT(0);
            break;
        case RCC_CLOCK_HSI:
            RCC_CR &= ~BIT(0);
            break;
        case RCC_CLOCK_HSE:
            RCC_CR &= ~BIT(16);
            break;
        case RCC_CLOCK_LSE:
            RCC_BDCR &= ~BIT(0);
            break;
        case RCC_CLOCK_LSI:
            RCC_CSR &= ~BIT(0);
            break;
        case RCC_CLOCK_PLL:
            RCC_CR &= ~BIT(24);
            break;
	}
}

bool rcc_clock_ready(rcc_clock_t clock){
    switch (clock) {
	case RCC_CLOCK_HSI48:
		return RCC_CR2 & BIT(17);
	case RCC_CLOCK_HSI14:
		return RCC_CR2 & BIT(1);
	case RCC_CLOCK_HSI:
		return RCC_CR & BIT(1);
	case RCC_CLOCK_HSE:
		return RCC_CR & BIT(17);
	case RCC_CLOCK_PLL:
		return RCC_CR & BIT(25);
	case RCC_CLOCK_LSE:
		return RCC_BDCR & BIT(1);
	case RCC_CLOCK_LSI:
		return RCC_CSR & BIT(1);
	}
	return false;
}

void rcc_pll_set_clock_source(rcc_clock_t clock, bool hsiDiv2){
    uint32_t tempReg = RCC_CSR & ~(BIT(15) | BIT(16));
    switch (clock)
    {
    case RCC_CLOCK_HSI:
        if(!hsiDiv2) tempReg |= BIT(15); 
        break;
    case RCC_CLOCK_HSI48:
        tempReg |= BIT(15) | BIT(16);
        break;
    case RCC_CLOCK_HSE:
        tempReg |= BIT(16);
        break;
    default:
        return;
    }
    RCC_CSR = tempReg;
}

void rcc_pll_set_multiplier(uint32_t mul){
    if(mul < 2 || mul > 16) return;
    mul -= 2;
    RCC_CFGR = (RCC_CFGR & ~(BIT(18) | BIT(19) | BIT(20) | BIT(21))) | (mul << 18);
}   

void rcc_pclk_div_set(rcc_pclk_div_t ppre){
    RCC_CFGR = (RCC_CFGR & ~(BIT(8) | BIT(9) | BIT(10))) | ppre;
}

void rcc_hclk_div_set(rcc_hclk_div_t hpre){
    RCC_CFGR = (RCC_CFGR & ~(BIT(4) | BIT(5) | BIT(6) | BIT(7))) | hpre;
}

void rcc_prediv_set(uint32_t prediv){
    prediv &= 0xf;
    RCC_CSR = (RCC_CSR & ~(0xf)) | prediv;
}

void rcc_rtc_set_clock_source(rcc_clock_t clock){
    //TODO:
}

void rcc_rtc_clock_enable(){
    RCC_BDCR |= BIT(15);
}

void rcc_rtc_clock_disable(){
    RCC_BDCR &= ~BIT(15);
}

void rcc_system_set_clock_source(rcc_clock_t clock){
    uint32_t tempReg = RCC_CFGR & ~(BIT(0) | BIT(1));
    switch (clock) {
        case RCC_CLOCK_HSI:
            tempReg |= 0;
            break;
        case RCC_CLOCK_HSE:
            tempReg |= BIT(0);
            break;
        case RCC_CLOCK_PLL:
            tempReg |= BIT(1);
            break;
        case RCC_CLOCK_HSI48:
            tempReg |= BIT(0) | BIT(1);
            break;
        default:
            break;
	}
    RCC_CFGR = tempReg;
}

static void flash_prefetch_enable(){
    REG(0x40022000) |= BIT(4);
}

static void flash_wait_state_24_48mhz(){
    REG(0x40022000) &= ~(BIT(1) | BIT(2));
    REG(0x40022000) |= BIT(0);
}

void rcc_clock_setup_hsi_48mhz(){
    rcc_clock_enable(RCC_CLOCK_HSI);
    while(!rcc_clock_ready(RCC_CLOCK_HSI));
    rcc_system_set_clock_source(RCC_CLOCK_HSI);

    rcc_hclk_div_set(RCC_HCLK_DIV_0);
    rcc_pclk_div_set(RCC_PCLK_DIV_0);

    flash_prefetch_enable();
    flash_wait_state_24_48mhz();

    rcc_pll_set_multiplier(12);
    rcc_pll_set_clock_source(RCC_CLOCK_HSI, true);

    rcc_prediv_set(0);

    rcc_clock_enable(RCC_CLOCK_PLL);
    while(!rcc_clock_ready(RCC_CLOCK_PLL));
    rcc_system_set_clock_source(RCC_CLOCK_PLL);

    rcc_sys_freq = 48000000;
    rcc_apb_freq = rcc_sys_freq;
    rcc_ahb_freq = rcc_sys_freq;
}

uint64_t rcc_get_sys_freq(){
	return rcc_sys_freq;
}

uint64_t rcc_get_ahb_freq(){
	return rcc_ahb_freq;
}

uint64_t rcc_get_apb1_freq(){
	return rcc_apb_freq;
}

uint64_t rcc_get_apb2_freq(){
	return rcc_apb_freq;
}

