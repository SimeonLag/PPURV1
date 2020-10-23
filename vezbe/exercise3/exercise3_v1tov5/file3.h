/*
 * file3.h
 *
 *  Created on: Oct 14, 2020
 *      Author: rtrk
 */
extern int global_variable;//deklaracija
static int non_init;
static int init_1;
extern int public_init;

void use_it();
void increment();

void change(int a);
void print();
