/*
 * list.h
 *
 *  Created on: Oct 21, 2020
 *      Author: rtrk
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define NAME_SIZE 5
#define GROUP_NAME_SIZE 5

typedef struct employees {
 char name[NAME_SIZE];
 char group[GROUP_NAME_SIZE];
 float experience;
 struct employees* prev;
 struct employees* next;
}employee;

typedef struct EmployeeLists {
	employee* head; // Pointer to first element in list
	employee* tail; // Pointer to last element in list
}EmployeeList;

void EmployeeListCreate(EmployeeList*);
void EmployeeListDestroy(EmployeeList*);
void EmployeeListInsert(EmployeeList*, employee*, employee*);
void EmployeeListDelete(EmployeeList*, employee*);
int_least8_t EmployeeListEmpty(EmployeeList*);

#endif /* LIST_H_ */
