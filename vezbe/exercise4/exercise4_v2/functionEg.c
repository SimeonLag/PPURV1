#include "functionEg.h"


int_least32_t factorial(int_least16_t n)
{
	if(0 == n) {
		return 1;
	}
	return n*factorial(n-1);
	/*int_least32_t temp = 1;
	int_least16_t i = 0;
	for(i=1;i<=n;i++) {
		temp = temp*i;
	}
	return temp;*/
}

int_least32_t fibonacci(int_least16_t n)
{
	/*if(1 < n) {
		return fibonacci(n-1) + fibonacci(n-2);
	}
	else {
		return n;
	}
	return 0;*/
	int_least32_t fib1 = 0;
	int_least32_t fib2 = 1;
	int_least32_t fib3 = 0;
	int_least16_t i = 0;
	for(i = 1;i<n;i++) {
		fib3 = fib1 + fib2;
		fib1 = fib2;
		fib2 = fib3;
	}
	return fib3;
}

