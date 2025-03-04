/*
 * fifo.c
 *
 *  Created on: 26 feb. 2025
 *      Author: geert
 */

#include "fifo.h"

static fifo_state_t fifo_increment_read_pointer(fifo_t* fifo){
    if(fifo->readPointer == fifo->writePointer) return FIFO_STATE_BUFFER_EMPTY;
    fifo->readPointer = (fifo->readPointer + 1) % fifo->bufferSize;
    return FIFO_STATE_OK;
}

static fifo_state_t fifo_increment_write_pointer(fifo_t* fifo){
    uint32_t writePointer = fifo->writePointer;
    writePointer = (writePointer + 1) % fifo->bufferSize;
    if(fifo->readPointer == writePointer) return FIFO_STATE_BUFFER_FULL;
    fifo->writePointer = writePointer;
    return FIFO_STATE_OK;
}

void fifo_init(fifo_t* fifo, uint8_t* buffer, uint32_t bufferSize){
    fifo->buffer = buffer;
    fifo->bufferSize = bufferSize;
    fifo->readPointer = 0;
    fifo->writePointer = 0;
}

void fifo_write_byte(fifo_t* fifo, uint8_t data){
    if(!fifo_bytes_free(fifo)) return;
    fifo->buffer[fifo->writePointer] = data;
    fifo_increment_write_pointer(fifo);
}

uint8_t fifo_read_byte(fifo_t* fifo){
    if(fifo_bytes_ready(fifo)){
        uint8_t data = fifo->buffer[fifo->readPointer];
        fifo_increment_read_pointer(fifo);
        return data;
    }else{
        return 0;
    }
}

uint8_t fifo_peek_byte(fifo_t* fifo){
    if(fifo_bytes_ready(fifo)){
        return fifo->buffer[fifo->readPointer];
    }else{
        return 0;
    }
}

void fifo_next_byte(fifo_t* fifo){
    fifo_increment_read_pointer(fifo);
}

uint32_t fifo_bytes_ready(fifo_t* fifo){
    if(fifo->readPointer == fifo->writePointer) return 0;
    if(fifo->readPointer < fifo->writePointer){
        return (fifo->writePointer - fifo->readPointer);
    }else{
        return (fifo->writePointer + (fifo->bufferSize - fifo->readPointer));
    }
}

uint32_t fifo_bytes_free(fifo_t* fifo){
    if(fifo->readPointer == fifo->writePointer) return fifo->bufferSize;
    if(fifo->readPointer < fifo->writePointer){
        return (fifo->readPointer + (fifo->bufferSize - fifo->writePointer));
    }else{
        return (fifo->readPointer - fifo->writePointer);
    }
}

fifo_state_t fifo_write_block(fifo_t* fifo, uint8_t* buffer, uint32_t count){
    if(fifo_bytes_free(fifo) < count) return FIFO_SATTE_NOT_READY;
    for (int i = 0; i < count; i++)
    {
        fifo_write_byte(fifo, buffer[i]);
    }
    return FIFO_STATE_OK;
}

fifo_state_t fifo_read_block(fifo_t* fifo, uint8_t* buffer, uint32_t count){
    if(fifo_bytes_ready(fifo) < count) return FIFO_SATTE_NOT_READY;
    for (int i = 0; i < count; i++)
    {
        buffer[i] = fifo_read_byte(fifo);
    }
    return FIFO_STATE_OK;
}
