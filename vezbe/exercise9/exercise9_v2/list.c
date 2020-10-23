/*
 * list.c
 *
 *  Created on: Oct 21, 2020
 *      Author: rtrk
 */

#include "list.h"

void EmployeeListCreate(EmployeeList* list) {
	list->head = NULL;
	list->tail = NULL;
}

void EmployeeListDestroy(EmployeeList* list) {
	employee* temp = list->head;
	employee* delete;
	while(temp != NULL) {
		delete = temp;
		temp = temp->next;
		free(delete);
	}
	free(temp);
	list->head = NULL;
	list->tail = NULL;
}

void EmployeeListInsert(EmployeeList* list, employee* p, employee* elem) {
	if(p == list->head) {
		elem->next = list->head->next;
		list->head = elem;
		elem->prev = NULL;
	}
	else if(p == list->tail) {
		elem->prev = list->tail->prev;
		list->tail = elem;
		elem->next = NULL;
	}
	else {
		elem->next = p->next;
		p->next = elem;
		elem->prev = p;
	}
}

void EmployeeListDelete(EmployeeList* list, employee* p) {
	if(p == list->head) {
		list->head = p->next;
		p->next = NULL;
		p->prev = NULL;
		free(p);
	}
	else if(p == list->tail) {
		list->tail = p->prev;
		p->next = NULL;
		p->prev = NULL;
		free(p);
	}
	else {
		p->prev->next = p->next;
		p->next->prev = p->prev;
		p->next = NULL;
		p->prev = NULL;
		fre(p);
	}
}

int_least8_t EmployeeListEmpty(EmployeeList* list){
	if(list->head == NULL) {
		return 1;
	}
	return 0;
}

void EmployeeListDump(EmployeeList* list) {
	employee* p = list->head;
	while(p->next != NULL) {
		printf("Struct element:%d\n", p);
		printf("%s\n", p->name);
		printf("%s\n", p->group);
		printf("%f\n", p->experience);
		printf("%d\n", p->next);
		printf("%d\n", p->prev);
		printf("---------\n");
		p = p->next;
	}
}


