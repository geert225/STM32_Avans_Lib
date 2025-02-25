/*
 * spi.c
 *
 *  Created on: 15 feb. 2025
 *      Author: geert
 */

#include "spi.h"

void spi_enable(stm_register_t spi){
    BITS_SET(REG(spi + SPIx_CR1), BIT(6));
}

void spi_disable(stm_register_t spi){
    BITS_RESET(REG(spi + SPIx_CR1), BIT(6));
}

void spi_set_frame_format(stm_register_t spi, spi_frame_format_t format){
    BITS_WRITE(REG(spi + SPIx_CR1), BIT(7), (format == SPI_FRAME_FORMAT_LSB));
}

void spi_set_master_mode(stm_register_t spi){
    BITS_SET(REG(spi + SPIx_CR1), BIT(2));
}

void spi_set_software_slave_management(stm_register_t spi){
    BITS_SET(REG(spi + SPIx_CR1), BIT(9) | BIT(8));
}

void spi_set_baudrate(stm_register_t spi, spi_baudrate_t baudrate){
    REG(spi + SPIx_CR1) = (REG(spi + SPIx_CR1) & ~(0x38)) | (baudrate << 3);
}

void spi_set_mode(stm_register_t spi, spi_mode_t mode){
    REG(spi + SPIx_CR1) = (REG(spi + SPIx_CR1) & ~(3)) | mode;
}

void spi_set_data_size(stm_register_t spi, spi_data_size_t size){
    if(size == SPI_DATA_SIZE_16){
        REG(spi + SPIx_CR2) = (REG(spi + SPIx_CR2) & ~(0x1f00)) | 0x0F00;
    }else{
        REG(spi + SPIx_CR2) = (REG(spi + SPIx_CR2) & ~(0x1f00)) | 0x1700;
    }
}

uint8_t spi_read(stm_register_t spi){
    return spi_transfer(spi, 0x00);
}

void spi_write(stm_register_t spi, uint8_t data){
	spi_transfer(spi, data);
}

uint8_t spi_transfer(stm_register_t spi, uint8_t data){
    while (!(REG(spi + SPIx_SR) & BIT(1)));
    REG_8(spi + SPIx_DR) = data;
    while (!(REG(spi + SPIx_SR) & BIT(0)));
    uint8_t rx = REG_8(spi + SPIx_DR);
    return rx;
}
