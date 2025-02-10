/*
 * nvic.h
 *
 *  Created on: 8 feb. 2025
 *      Author: geert
 */

#include "nvic.h"
#include "../registers/nvic.h"

void nvic_enable_irq(nvic_irq_t irq){
    NVIC_ISER = BIT(irq);
}

void nvic_disable_irq(nvic_irq_t irq){
    NVIC_ICER = BIT(irq);
}

bool nvic_irq_enabled(nvic_irq_t irq){
    return (NVIC_ICER & BIT(irq));
}

void nvic_set_irq_pending(nvic_irq_t irq){
    NVIC_ISPR = BIT(irq);
}

void nvic_clear_irq_pending(nvic_irq_t irq){
    NVIC_ICPR = BIT(irq);
}

bool nvic_irq_pending(nvic_irq_t irq){
    return (NVIC_ISPR & BIT(irq));
}

void nvic_set_irq_priority(nvic_irq_t irq, uint32_t priority){
    int reg = (irq - (irq % 4)) / 4;
    int offset = ((irq % 4) << 2);

    REG(NVIC_IPR_BASE_ADDR + reg) = (REG(NVIC_IPR_BASE_ADDR + reg) & (0xff << offset)) | ((priority & 0xff) << offset); 
}

uint32_t nvic_get_irq_priority(nvic_irq_t irq){
    int reg = (irq - (irq % 4)) / 4;
    int offset = ((irq % 4) << 2);
    return (REG(NVIC_IPR_BASE_ADDR + reg) >> offset) & 0xff;
}