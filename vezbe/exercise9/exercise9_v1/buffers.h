/*
 * buffers.h
 *
 *  Created on: Oct 21, 2020
 *      Author: rtrk
 */

#ifndef BUFFERS_H_
#define BUFFERS_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define TYPE int32_t
#define N 5

typedef struct CircularBuffers{
	TYPE data[N+1];
	TYPE* head;
	TYPE* tail;
}CircularBuffer;

void CircularInit(CircularBuffer*);
int_least8_t CircularIsFull(CircularBuffer*);
void CircularPut(CircularBuffer*, TYPE);
TYPE CircularGet(CircularBuffer*);
void CircularEmptyBuff(CircularBuffer*);
void CircularDump(CircularBuffer*);

#endif /* BUFFERS_H_ */
