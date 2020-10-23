#ifndef CIRCULARBUFFER_H_
#define CIRCULARBUFFER_H_

#include <stdbool.h>

#define CIRCULAR_BUFFER_SIZE 11
#define CIRCULAR_BUFFER_ERROR (-1111111111)
#define CIRCULAR_BUFFER_TYPE_PRINT "d"

typedef int CircularBuffer_Type;

typedef int (*CircularBuffer_PrintFunction)(const char *__restrict __format, ...);

typedef struct CircularBufferStruct
{
	CircularBuffer_Type Buffer[CIRCULAR_BUFFER_SIZE];
	CircularBuffer_Type* Front;
	CircularBuffer_Type* Rear;
} CircularBuffer;

void CircularBuffer_Init(CircularBuffer* CircBuf);

bool CircularBuffer_IsEmpty(CircularBuffer* CircBuf);

bool CircularBuffer_IsFull(CircularBuffer* CircBuf);

bool CircularBuffer_Put(CircularBuffer* CircBuf, CircularBuffer_Type Data);

CircularBuffer_Type CircularBuffer_Get(CircularBuffer* CircBuf);

void CircularBuffer_Reset(CircularBuffer* CircBuf);

void CircularBuffer_Print(CircularBuffer* CircBuf, CircularBuffer_PrintFunction Print);

#endif /*CIRCULARBUFFER_H_*/
