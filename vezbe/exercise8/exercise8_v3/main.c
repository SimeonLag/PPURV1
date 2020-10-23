/*
 * main.c
 *
 *  Created on: Oct 20, 2020
 *      Author: rtrk
 */
#include <dlfcn.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CEASAR_SHIFT  3

int main()
{
	void* handle;
	void (*encryptCeasar)(const char* in, char* out, int_fast16_t shift);
	void (*decryptCeasar)(const char* in, char* out, int_fast16_t shift);
	char* error;
	handle = dlopen("libcaesar12.so", RTLD_LAZY);
	if (handle == NULL)
	{
		fputs(dlerror(), stderr);
		exit(1);
	}
	encryptCeasar = dlsym(handle, "encryptCeasar");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	decryptCeasar = dlsym(handle, "decryptCeasar");
	if ((error = dlerror()) != NULL)
	{
		fputs(error, stderr);
		exit(1);
	}

	char in[100] = "the QUICK brown FOX jumps over THE lazy DOG";
	char encrypted[100];
	char decrypted[100];

	printf("Ceasar cipher (shift %d) :\n", CEASAR_SHIFT);
	encryptCeasar(in, encrypted, CEASAR_SHIFT);
	printf("Original: %s\nencrypted: %s\n", in, encrypted);
	decryptCeasar(encrypted, decrypted, CEASAR_SHIFT);
	printf("decrypted: %s\n", decrypted);
	printf("\n");

	dlclose(handle);
	return 0;
}

