/*
 * main.c
 *
 *  Created on: Nov 1, 2019
 *      Author: rtrk
 */

#include "Echo.h"

#ifdef ECHO_TEST
#include "EchoTest/EchoTest.h"
#endif

#define INPUT_MAXSIZE 100

int main()
{
#ifdef ECHO_TEST
	return EchoTest_Run();
#endif

	char Input[INPUT_MAXSIZE];

	Echo(Input, INPUT_MAXSIZE);

	return 0;
}
