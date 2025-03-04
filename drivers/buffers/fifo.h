/*
 * fifo.h
 *
 *  Created on: 26 feb. 2025
 *      Author: geert
 */

#ifndef DRIVERS_BUFFERS_FIFO_H_
#define DRIVERS_BUFFERS_FIFO_H_

#include "../../common.h"

typedef struct 
{
    uint8_t* buffer;
    uint32_t bufferSize;
    uint32_t writePointer;
    uint32_t readPointer;
} fifo_t;

typedef enum {
	FIFO_STATE_OK,
    FIFO_STATE_BUFFER_FULL,
    FIFO_STATE_BUFFER_EMPTY,
    FIFO_SATTE_NOT_READY
} fifo_state_t;

void fifo_init(fifo_t* fifo, uint8_t* buffer, uint32_t bufferSize);
void fifo_write_byte(fifo_t* fifo, uint8_t data);
uint8_t fifo_read_byte(fifo_t* fifo); 
uint8_t fifo_peek_byte(fifo_t* fifo);
void fifo_next_byte(fifo_t* fifo);  
uint32_t fifo_bytes_ready(fifo_t* fifo);
uint32_t fifo_bytes_free(fifo_t* fifo);
fifo_state_t fifo_write_block(fifo_t* fifo, uint8_t* buffer, uint32_t count);
fifo_state_t fifo_read_block(fifo_t* fifo, uint8_t* buffer, uint32_t count); 

#endif /* DRIVERS_BUFFERS_FIFO_H_ */
