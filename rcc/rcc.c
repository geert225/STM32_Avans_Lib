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
