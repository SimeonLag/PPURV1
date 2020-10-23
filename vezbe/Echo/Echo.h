/*
 * Echo.h
 *
 *  Created on: Nov 6, 2019
 *      Author: rtrk
 */

#ifndef ECHO_H_
#define ECHO_H_

#include <stdio.h>

//#define ECHO_TEST

typedef int (*Echo_PrintFunction)(const char *__restrict __format, ...);
typedef FILE* Echo_InputDescriptor;

extern Echo_PrintFunction EchoPrint;
extern Echo_InputDescriptor EchoInputSource;

void Echo(char* Input, int InputMaxLength);

#endif /* ECHO_H_ */
