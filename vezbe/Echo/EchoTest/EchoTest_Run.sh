#!/bin/sh

cd ../Debug

EchoTest_EmptyString()
{
	echo -n "EchoTest_EmptyString:"

	expectedOutput=""
	programOutput=$(./Echo < ../EchoTest/EchoTest_EmptyString.txt)

	TEST_ASSERT_EQUAL_STRING "$expectedOutput" "$programOutput"
}

EchoTest_StringFitsIntoSizeLimit()
{
	echo -n "EchoTest_StringFitsIntoSizeLimit:"

	expectedOutput="This String Certainly Fits Into Input Limits Of The ECHO ECHO Program."
	programOutput=$(./Echo < ../EchoTest/EchoTest_StringFitsIntoSizeLimit.txt)

	TEST_ASSERT_EQUAL_STRING "$expectedOutput" "$programOutput"
}

TEST_ASSERT_EQUAL_STRING()
{
	if [ "$1" = "$2" ]; then
	    echo "PASS"
	else
	    echo "FAIL: Expected '"$1"' Was '"$2"'"
	fi
}

EchoTest_StringFitsIntoSizeLimit
EchoTest_EmptyString
