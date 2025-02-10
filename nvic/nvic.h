/*
 * nvic.h
 *
 *  Created on: 8 feb. 2025
 *      Author: geert
 */

#ifndef NVIC_NVIC_H_
#define NVIC_NVIC_H_

#include "../common.h"

#define NVIC_DEFAULT_PRIORITY_SVCALL 3
#define NVIC_DEFAULT_PRIORITY_PENDSV 5
#define NVIC_DEFAULT_PRIORITY_SYSTICK 6

#define NVIC_PRIORITY_MIN 0
#define NVIC_PRIORITY_START 8 //bereik waarvanaf we starten 
#define NVIC_PRIORITY_MAX 192

typedef enum {
    NVIC_IRQ_WWDG       = (0),
    NVIC_IRQ_PVD        = (1),
    NVIC_IRQ_VDDIO2     = (1),
    NVIC_IRQ_RTC        = (2),
    NVIC_IRQ_FLASH      = (3),
    NVIC_IRQ_RCC        = (4),
    NVIC_IRQ_CRC        = (4),
    NVIC_IRQ_EXTI0      = (5),
    NVIC_IRQ_EXTI1      = (5),
    NVIC_IRQ_EXTI2      = (6),
    NVIC_IRQ_EXTI3      = (6),
    NVIC_IRQ_EXTI4      = (7),
    NVIC_IRQ_EXTI5      = (7),
    NVIC_IRQ_EXTI6      = (7),
    NVIC_IRQ_EXTI7      = (7),
    NVIC_IRQ_EXTI8      = (7),
    NVIC_IRQ_EXTI9      = (7),
    NVIC_IRQ_EXTI10     = (7),
    NVIC_IRQ_EXTI11     = (7),
    NVIC_IRQ_EXTI12     = (7),
    NVIC_IRQ_EXTI13     = (7),
    NVIC_IRQ_EXTI14     = (7),
    NVIC_IRQ_EXTI15     = (7),
    NVIC_IRQ_TSC        = (8),
    NVIC_IRQ_DMA_CH1    = (9),
    NVIC_IRQ_DMA_CH2    = (10),
    NVIC_IRQ_DMA_CH3    = (10),
    NVIC_IRQ_DMA2_CH1   = (10),
    NVIC_IRQ_DMA2_CH2   = (10),
    NVIC_IRQ_DMA_CH4    = (11),
    NVIC_IRQ_DMA_CH5    = (11),
    NVIC_IRQ_DMA_CH6    = (11),
    NVIC_IRQ_DMA_CH7    = (11),
    NVIC_IRQ_DMA2_CH3   = (11),
    NVIC_IRQ_DMA2_CH4   = (11),
    NVIC_IRQ_DMA2_CH5   = (11),
    NVIC_IRQ_ADC        = (12),
    NVIC_IRQ_COMP       = (12),
    NVIC_IRQ_TIM1_BRK   = (13),
    NVIC_IRQ_TIM1_UPD   = (13),
    NVIC_IRQ_TIM1_TRG   = (13),
    NVIC_IRQ_TIM1_COM   = (13),
    NVIC_IRQ_TIM1_CC    = (14),
    NVIC_IRQ_TIM2       = (15),
    NVIC_IRQ_TIM3       = (16),
    NVIC_IRQ_TIM6       = (17),
    NVIC_IRQ_DAC        = (17),
    NVIC_IRQ_TIM7       = (18),
    NVIC_IRQ_TIM14      = (19),
    NVIC_IRQ_TIM15      = (20),
    NVIC_IRQ_TIM16      = (21),
    NVIC_IRQ_TIM17      = (22),
    NVIC_IRQ_I2C1       = (23),
    NVIC_IRQ_I2C2       = (24),
    NVIC_IRQ_SPI1       = (25),
    NVIC_IRQ_SPI2       = (26),
    NVIC_IRQ_USART1     = (27),
    NVIC_IRQ_USART2     = (28),
    NVIC_IRQ_USART3     = (29),
    NVIC_IRQ_USART4     = (29),
    NVIC_IRQ_USART5     = (29),
    NVIC_IRQ_USART6     = (29),
    NVIC_IRQ_USART7     = (29),
    NVIC_IRQ_USART8     = (29),
    NVIC_IRQ_CEC        = (30),
    NVIC_IRQ_CAN        = (30),
    NVIC_IRQ_USB        = (31),
} nvic_irq_t;

void nvic_enable_irq(nvic_irq_t irq);
void nvic_disable_irq(nvic_irq_t irq);
bool nvic_irq_enabled(nvic_irq_t irq);
void nvic_set_irq_pending(nvic_irq_t irq);
void nvic_clear_irq_pending(nvic_irq_t irq);
bool nvic_irq_pending(nvic_irq_t irq);
void nvic_set_irq_priority(nvic_irq_t irq, uint32_t priority);
uint32_t nvic_get_irq_priority(nvic_irq_t irq);

static inline void nvic_enable_global_interrupts(){
    asm volatile ("CPSIE I\n");
}

static inline void nvic_disable_global_interrupts(){
    asm volatile ("CPSID I\n");
}

#endif /* NVIC_NVIC_H_ */
