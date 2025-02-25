/*
 * spi.h
 *
 *  Created on: 15 feb. 2025
 *      Author: geert
 */

#ifndef SPI_SPI_H_
#define SPI_SPI_H_

#include "../common.h"
#include "../registers/spi.h"

typedef enum {
    SPI_1 = SPI1_BASE_ADDR,
    SPI_2 = SPI2_BASE_ADDR
} spi_t;

typedef enum {
    SPI_MODE_0 = 0,                 //CPOL = 0, CPHA = 0
    SPI_MODE_1 = BIT(0),            //CPOL = 0, CPHA = 1
    SPI_MODE_2 = BIT(1),            //CPOL = 1, CPHA = 0
    SPI_MODE_3 = BIT(0) | BIT(1)    //CPOL = 1, CPHA = 1
} spi_mode_t;

typedef enum {
    SPI_BAUDRATE_DIV2 = 0,
    SPI_BAUDRATE_DIV4 = 1,
    SPI_BAUDRATE_DIV8 = 2,
    SPI_BAUDRATE_DIV16 = 3,
    SPI_BAUDRATE_DIV32 = 4,
    SPI_BAUDRATE_DIV64 = 5,
    SPI_BAUDRATE_DIV128 = 6,
    SPI_BAUDRATE_DIV256 = 7
} spi_baudrate_t;

typedef enum {
    SPI_FRAME_FORMAT_MSB = 0,
    SPI_FRAME_FORMAT_LSB = 1
} spi_frame_format_t;

typedef enum {
    SPI_DATA_SIZE_8,
    SPI_DATA_SIZE_16
} spi_data_size_t;

void spi_enable(stm_register_t spi);
void spi_disable(stm_register_t spi);

void spi_set_frame_format(stm_register_t spi, spi_frame_format_t format);
void spi_set_master_mode(stm_register_t spi);
void spi_set_software_slave_management(stm_register_t spi);
void spi_set_baudrate(stm_register_t spi, spi_baudrate_t baudrate);
void spi_set_mode(stm_register_t spi, spi_mode_t mode);
void spi_set_data_size(stm_register_t spi, spi_data_size_t size);

uint8_t spi_read(stm_register_t spi);
void spi_write(stm_register_t spi, uint8_t data);
uint8_t spi_transfer(stm_register_t spi, uint8_t data);

#endif /* SPI_SPI_H_ */
