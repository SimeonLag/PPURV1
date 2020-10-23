/*
 * main.c
 *
 *  Created on: Oct 21, 2020
 *      Author: rtrk
 */

#include "buffers.h"

int main() {
	CircularBuffer baff;
	TYPE x = 5;

	CircularInit(&baff);
	if(CircularIsFull(&baff)){
		printf("Buffer is full!");
	}
	CircularPut(&baff, x);
	x=6;
	CircularPut(&baff, x);
	x = 7;
	CircularPut(&baff, x);
	//printf("%d\n", CircularGet(&baff));
	//CircularEmptyBuff(&baff);
	CircularDump(&baff);
	printf("EXIT\n");
	return 0;
}
