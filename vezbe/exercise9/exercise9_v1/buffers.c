/*
 * buffers.c
 *
 *  Created on: Oct 21, 2020
 *      Author: rtrk
 */

#include "buffers.h"

void CircularInit(CircularBuffer* buff){
	buff->head = buff->data;
	buff->tail = buff->data;
}

int_least8_t CircularIsFull(CircularBuffer* buff){
	if(buff->head == buff->tail+1) {
		return 1;
	}
	if((buff->head == buff->data) && (buff->tail == buff->data+N-1)){
		return 1;
	}
	return 0;
}

int_least8_t CircularIsEmpty(CircularBuffer* buff) {
	if(buff->head == buff->tail) {
		return 1;
	}
	return 0;
}

void CircularPut(CircularBuffer* buff, TYPE data){
	if(!((buff->tail+1 == buff->head) || (buff->head == buff->data && buff->tail == data+N-1))){
		*(buff->tail) = data;
		if(buff->tail+1 == buff->data+N-1) {
			buff->tail = buff->data;
		}
		else{
			buff->tail++;
		}
		printf("Element added.\n");
	}
	else{
		printf("Buffer is full...\n");
	}
}

TYPE CircularGet(CircularBuffer* buff) {
	if(buff->head == buff->tail){
		printf("Buffer is empty...\n");
	}
	else{
		TYPE retVal = *(buff->head);
		if(buff->head == buff->data+N-1){
			buff->head = buff->data;
			return retVal;
		}
		buff->head++;
		return retVal;
	}
}

void CircularEmptyBuff(CircularBuffer* buff) {
	buff->head = buff->tail;
}

void CircularDump(CircularBuffer* buff) {
	printf("dumping buffer...\n");
	while(buff->head != buff->tail) {
		printf("%d\n", *(buff->head));
		if(buff->head == buff->data+N-1) {
			buff->head = buff->data;
		}
		else{
			buff->head++;
		}
	}
}
