/*
 * Echo.c
 *
 *  Created on: Nov 5, 2019
 *      Author: rtrk
 */

#include <stdio.h>
#include <string.h>
#include "Echo.h"
#include "CircularBuffer.h"

#include <unistd.h>

Echo_PrintFunction EchoPrint = printf;
Echo_InputDescriptor EchoInputSource;

void Echo(char* Input, int InputMaxLength)
{
	CircularBuffer Buffer;

#ifndef ECHO_TEST
	EchoInputSource = stdin;
#endif

	CircularBuffer_Init(&Buffer);

	int i = 0;

	if(fgets(Input, InputMaxLength, EchoInputSource) != NULL)
	{
		while(i < strlen(Input))
		{
			do
			{
				CircularBuffer_Put(&Buffer, Input[i++]);
			} while(i < strlen(Input) && !CircularBuffer_IsFull(&Buffer));

			while(!CircularBuffer_IsEmpty(&Buffer))
			{
				EchoPrint("%c", CircularBuffer_Get(&Buffer));
				if(EchoPrint == printf) {
					fflush(stdout);
				}
			}
		}
	}
	else
	{
		printf("Input error occured.\n");
	}

	return;
}
