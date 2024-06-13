#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

#define MAX 50

void initStack(StackArrayList *s){
	s->count = TOP
}

StackArrayList createStack(){
	StackArrayList s;
	s.count = TOP;
	return s;
}

bool isEmpty(StackArrayList s){
	return s.count == TOP;
}

bool isFull(StackArrayList s){
	return s.count == MAX - 1;
}

bool stack_push(StackArrayList *s, int elem){
	if (isFull(*s)){
		return false;
	}
	s->data[++(s->count)] = elem;
	return true;
}

bool stack_pop(StackArrayList *s){
	
}

int stack_peek(StackArrayList s){
	
}

void display(StackArrayList s){
	
}

void visualize(StackArrayList s){
	
}
