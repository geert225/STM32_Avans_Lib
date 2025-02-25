/*
 * spi.h
 *
 *  Created on: 15 feb. 2025
 *      Author: geert
 */

#ifndef REGISTERS_SPI_H_
#define REGISTERS_SPI_H_

#include "reg.h"

#define SPI1_BASE_ADDR (0x40013000)
#define SPI2_BASE_ADDR (0x40003800)

/* address offsets for specific gpio registers */
#define SPIx_CR1 	    (0x00) //SPI control register 1
#define SPIx_CR2 	    (0x04) //SPI control register 2
#define SPIx_SR 	    (0x08) //SPI status register
#define SPIx_DR 	    (0x0c) //SPI data register
#define SPIx_CRCPR 		(0x10) //SPI CRC polynomial register
#define SPIx_RXCRCR     (0x14) //SPI Rx CRC register
#define SPIx_TXCRCR     (0x18) //SPI Tx CRC register
#define SPIx_I2SCFGR    (0x1c) //SPIx_I2S configuration register
#define SPIx_I2SPR 		(0x20) //SPIx_I2S prescaler register

#define SPI1_CR1        REG(SPI1_BASE_ADDR + SPIx_CR1)
#define SPI1_CR2        REG(SPI1_BASE_ADDR + SPIx_CR2)
#define SPI1_SR         REG(SPI1_BASE_ADDR + SPIx_SR)
#define SPI1_DR         REG_16(SPI1_BASE_ADDR + SPIx_DR)
#define SPI1_CRCPR      REG(SPI1_BASE_ADDR + SPIx_CRCPR)
#define SPI1_RXCRCR     REG(SPI1_BASE_ADDR + SPIx_RXCRCR)
#define SPI1_TXCRCR     REG(SPI1_BASE_ADDR + SPIx_TXCRCR)
#define SPI1_I2SCFGR    REG(SPI1_BASE_ADDR + SPIx_I2SCFGR)
#define SPI1_I2SPR      REG(SPI1_BASE_ADDR + SPIx_I2SPR)

#define SPI2_CR1        REG(SPI2_BASE_ADDR + SPIx_CR1)
#define SPI2_CR2        REG(SPI2_BASE_ADDR + SPIx_CR2)
#define SPI2_SR         REG(SPI2_BASE_ADDR + SPIx_SR)
#define SPI2_DR         REG_16(SPI2_BASE_ADDR + SPIx_DR)
#define SPI2_CRCPR      REG(SPI2_BASE_ADDR + SPIx_CRCPR)
#define SPI2_RXCRCR     REG(SPI2_BASE_ADDR + SPIx_RXCRCR)
#define SPI2_TXCRCR     REG(SPI2_BASE_ADDR + SPIx_TXCRCR)
#define SPI2_I2SCFGR    REG(SPI2_BASE_ADDR + SPIx_I2SCFGR)
#define SPI2_I2SPR      REG(SPI2_BASE_ADDR + SPIx_I2SPR)

#endif /* REGISTERS_SPI_H_ */
