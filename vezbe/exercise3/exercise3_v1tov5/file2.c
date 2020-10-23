/*
 * file2.c
 *
 *  Created on: Oct 14, 2020
 *      Author: rtrk
 */
//#include "file3.h" //zakomentarisati za vezbu5

int global_variable;
int static non_init;
int static init_1 = 2;
int static public_init = 2;

void use_it(){
	global_variable++;
	printf("%d\n", global_variable);
}

void print(){
	//vezba 2
	//printf("%d\n", global_variable);

	//vezba3
	//printf("%d\n", non_init);

	//vezba4
	//printf("%d\n", init_1);

	//vezba5
	printf("%d\n", public_init);
}

