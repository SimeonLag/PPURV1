#include "CircularBuffer.h"

#include <stdio.h>
#include <stddef.h>

#define BUFFER_SIZE CIRCULAR_BUFFER_SIZE
#define BUFFER_GET_ERROR CIRCULAR_BUFFER_ERROR

void CircularBuffer_Init(CircularBuffer* CircBuf)
{
	CircBuf->Rear = CircBuf->Buffer;
	CircBuf->Front = CircBuf->Buffer;
}


bool CircularBuffer_IsEmpty(CircularBuffer* CircBuf)
{
	if (CircBuf->Front == CircBuf->Rear)
	{
		return true;
	}
	return false; 
}


bool CircularBuffer_IsFull(CircularBuffer* CircBuf)
{
	if (CircBuf->Front == (CircBuf->Rear + 1))
	{
		return true;
	}
	if ((CircBuf->Rear == &(CircBuf->Buffer[BUFFER_SIZE - 1])) && (CircBuf->Front == &(CircBuf->Buffer[0])))
	{
		return true;
	}
	return false; 
}


bool CircularBuffer_Put(CircularBuffer* CircBuf, CircularBuffer_Type Data)
{
	if (CircularBuffer_IsFull(CircBuf))
	{
		return false;
	}
	*(CircBuf->Rear) = Data;
	CircBuf->Rear++;
	if (CircBuf->Rear == &(CircBuf->Buffer[BUFFER_SIZE]))
	{
		CircBuf->Rear = &(CircBuf->Buffer[0]);
	}
	return true;
}


CircularBuffer_Type CircularBuffer_Get(CircularBuffer* CircBuf)
{
	if (CircularBuffer_IsEmpty(CircBuf))
	{
		return BUFFER_GET_ERROR;
	}
	CircularBuffer_Type Type;
	Type = *(CircBuf->Front);
	CircBuf->Front++;
	if (CircBuf->Front == &(CircBuf->Buffer[BUFFER_SIZE]))
	{
		CircBuf->Front = &(CircBuf->Buffer[0]);
	}
	return Type;
}


void CircularBuffer_Reset(CircularBuffer* CircBuf)
{
	(CircBuf->Front) = (CircBuf->Rear) = &(CircBuf->Buffer[0]);
}


void CircularBuffer_Print(CircularBuffer* CircBuf, CircularBuffer_PrintFunction Print)
{
	CircularBuffer_Type* Current = NULL;
	Current = CircBuf->Front;
	Print("Circular buffer content:\n<");

	while (!(Current == (CircBuf->Rear)))
	{
		Print("%"CIRCULAR_BUFFER_TYPE_PRINT, *Current);

		Current++;
		if (Current == &(CircBuf->Buffer[BUFFER_SIZE]))
		{
			Current = &(CircBuf->Buffer[0]);
		}

		if(Current != CircBuf->Rear)
		{
			Print(", ");
		}
	}

	Print(">\n");
}
