/*
 * rcc.c
 *
 *  Created on: 5 feb. 2025
 *      Author: geert
 */

#include "rcc.h"
#include "../registers/rcc.h"

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

void rcc_osc_enable(rcc_osc_t osc){
    switch (osc) {
        case RCC_OSC_HSI48:
            RCC_CR2 |= BIT(16);
            break;
        case RCC_OSC_HSI14:
            RCC_CR2 |= BIT(0);
            break;
        case RCC_OSC_HSI:
            RCC_CR |= BIT(0);
            break;
        case RCC_OSC_HSE:
            RCC_CR |= BIT(16);
            break;
        case RCC_OSC_LSE:
            RCC_BDCR |= BIT(0);
            break;
        case RCC_OSC_LSI:
            RCC_CSR |= BIT(0);
            break;
        case RCC_OSC_PLL:
            RCC_CR |= BIT(24);
            break;
	}
}

void rcc_osc_disable(rcc_osc_t osc){
    switch (osc) {
        case RCC_OSC_HSI48:
            RCC_CR2 &= ~BIT(16);
            break;
        case RCC_OSC_HSI14:
            RCC_CR2 &= ~BIT(0);
            break;
        case RCC_OSC_HSI:
            RCC_CR &= ~BIT(0);
            break;
        case RCC_OSC_HSE:
            RCC_CR &= ~BIT(16);
            break;
        case RCC_OSC_LSE:
            RCC_BDCR &= ~BIT(0);
            break;
        case RCC_OSC_LSI:
            RCC_CSR &= ~BIT(0);
            break;
        case RCC_OSC_PLL:
            RCC_CR &= ~BIT(24);
            break;
	}
}

bool rcc_osc_ready(rcc_osc_t osc){
    switch (osc) {
	case RCC_OSC_HSI48:
		return RCC_CR2 & BIT(17);
	case RCC_OSC_HSI14:
		return RCC_CR2 & BIT(1);
	case RCC_OSC_HSI:
		return RCC_CR & BIT(1);
	case RCC_OSC_HSE:
		return RCC_CR & BIT(17);
	case RCC_OSC_PLL:
		return RCC_CR & BIT(25);
	case RCC_OSC_LSE:
		return RCC_BDCR & BIT(1);
	case RCC_OSC_LSI:
		return RCC_CSR & BIT(1);
	}
	return false;
}

void rcc_pll_set_clock_source(rcc_osc_t osc, bool hsiDiv2){
    uint32_t tempReg = RCC_CSR & ~(BIT(15) | BIT(16));
    switch (osc)
    {
    case RCC_OSC_HSI:
        if(!hsiDiv2) tempReg |= BIT(15); 
        break;
    case RCC_OSC_HSI48:
        tempReg |= BIT(15) | BIT(16);
        break;
    case RCC_OSC_HSE:
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

void rcc_ppre_set(rcc_div_ppre_clken_t ppre){
    RCC_CFGR = (RCC_CFGR & ~(BIT(8) | BIT(9) | BIT(10))) | ppre;
}

void rcc_hpre_set(rcc_div_hpre_clken_t hpre){
    RCC_CFGR = (RCC_CFGR & ~(BIT(4) | BIT(5) | BIT(6) | BIT(7))) | hpre;
}

void rcc_prediv_set(uint32_t prediv){
    prediv &= 0xf;
    RCC_CSR = (RCC_CSR & ~(0xf)) | prediv;
}

void rcc_rtc_set_clock_source(rcc_osc_t osc){
    //TODO:
}

void rcc_rtc_clock_enable(){
    RCC_BDCR |= BIT(15);
}

void rcc_rtc_clock_disable(){
    RCC_BDCR &= ~BIT(15);
}

void rcc_system_set_clock_source(rcc_osc_t osc){
    uint32_t tempReg = RCC_CFGR & ~(BIT(0) | BIT(1));
    switch (osc) {
        case RCC_OSC_HSI:
            tempReg |= 0;
            break;
        case RCC_OSC_HSE:
            tempReg |= BIT(0);
            break;
        case RCC_OSC_PLL:
            tempReg |= BIT(1);
            break;
        case RCC_OSC_HSI48:
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
    rcc_osc_enable(RCC_OSC_HSI);
    while(!rcc_osc_ready(RCC_OSC_HSI));
    rcc_system_set_clock_source(RCC_OSC_HSI);

    rcc_hpre_set(RCC_HCLK_DIV_0);
    rcc_ppre_set(RCC_PCLK_DIV_0);

    flash_prefetch_enable();
    flash_wait_state_24_48mhz();

    rcc_pll_set_multiplier(12);
    rcc_pll_set_clock_source(RCC_OSC_HSI, true);

    rcc_prediv_set(0);

    rcc_osc_enable(RCC_OSC_PLL);
    while(!rcc_osc_ready(RCC_OSC_PLL));
    rcc_system_set_clock_source(RCC_OSC_PLL);
}
