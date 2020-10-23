/*
 * file1.c
 *
 *  Created on: Oct 14, 2020
 *      Author: rtrk
 */
#include "file3.h"

int global_variable = 0; //definicija
int static non_init;//dodeljuje nulu globalnim prom
int static init_1 = 1;
int public_init = 1; //vezba 5 ovde nastaje error

void increment(){
	global_variable++;
}

void change(int a){
	//vezba2
	//global_variable = a;

	//vezba3
	//non_init = a;

	//vezba4
	//init_1 = a;

	//vezba5 zakomentarisi include u file2
	public_init = a;
}

