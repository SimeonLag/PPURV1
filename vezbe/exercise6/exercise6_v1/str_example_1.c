/*
 * str_example_1.c
 *
 *  Created on: Oct 19, 2020
 *      Author: rtrk
 */
#include <stdint.h>

uint32_t stringLength(char str[]) {
	uint32_t i = 0;
	while(str[i] != '\0') {
		i++;
	}
	return i;
}

void stringTrim(char str[]) {
	int_fast8_t i = 0;
	int_fast8_t k = 0;
	while(str[i] == ' ') {
		i++;
	}
	while(k < stringLength(str)-i) {
		str[k] = str[i];
		str[i] = ' ';
		k++;
		i++;
	}
	printf("%d", i);
	//str = str + i; zasto ne moze ovako?


	i = stringLength(str);
	while(str[i-1] == ' '){
		i--;
	}
	str[i] = '\0';

}

uint8_t extractSubstring(const char* inStr, char* outStr, uint_least32_t beginning, uint_least32_t end) {
	uint8_t k = 0;
	uint8_t i = beginning;
	while(i <= end) {
		outStr[k] = inStr[i];
		k++;
		i++;
	}
	return 1;
}

uint8_t concateStrings(char* str1, const char* str2) {
	uint8_t i = stringLength(str1);
	uint8_t k = 0;
	while (k < stringLength(str2)) {
		str1[i] = str2[k];
		k++;
		i++;
	}
	return 1;
}



int main() {
	char str[40] = "Ovo je string";
	char trimStr[] = "   test    ";
	printf("Len:\n");
	printf("%u\n", stringLength(str));
	char str2[stringLength(str)];
	char str3[100];
	printf("Before trim:%s\n", trimStr);
	stringTrim(trimStr);
	printf("After trim:%s\n", trimStr);

	extractSubstring(str, str2, 4, 10);
	int i = 0;
	for(i=0;i<stringLength(str2); i++) {
		printf("%c", str2[i]);
	}
	printf("\n");
	for (i=0;i<10;i++) {
		str3[i] = 'A';
	}
	str3[10] = '\0';
	concateStrings(str, str3);
	for(i=0;i<stringLength(str);i++) {
		printf("%c", str[i]);
	}
}
