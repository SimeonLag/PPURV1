/*
 * EchoTest.c
 *
 *  Created on: Nov 6, 2019
 *      Author: rtrk
 */

#include "unity.h"
#include "EchoTest.h"
#include "FormatOutputSpy.h"
#include "../Echo.h"
#include <stdio.h>

#define INPUT_MAXSIZE 100

static char Input[INPUT_MAXSIZE];

void setUp(void)
{
	FormatOutputSpy_Create(INPUT_MAXSIZE);
	EchoPrint = FormatOutputSpy;
}

void tearDown(void)
{
	FormatOutputSpy_Destroy();
	EchoPrint = printf;
}

int EchoTest_Run()
{
	UNITY_BEGIN();

	RUN_TEST(EchoTest_EmptyString);
	RUN_TEST(EchoTest_StringFitsIntoSizeLimit);

	return UNITY_END();
}

void EchoTest_EmptyString()
{
	const char* expectedOutput = "\n";

	FILE* fp = fopen("EchoTest/EchoTest_EmptyString.txt", "r");
	EchoInputSource = fp;

	Echo(Input, INPUT_MAXSIZE);

	TEST_ASSERT_EQUAL_STRING(expectedOutput, FormatOutputSpy_GetOutput());

	fclose(fp);
}

void EchoTest_StringFitsIntoSizeLimit()
{
	//No. of chars: 72
	const char* expectedOutput =
			"This String Certainly Fits Into Input Limits Of The ECHO ECHO Program.\n";

	FILE* fp = fopen("EchoTest/EchoTest_StringFitsIntoSizeLimit.txt", "r");
	EchoInputSource = fp;

	Echo(Input, INPUT_MAXSIZE);

	TEST_ASSERT_EQUAL_STRING(expectedOutput, FormatOutputSpy_GetOutput());

	fclose(fp);
}
