#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1
}

StackArrayList createStack(){
	StackArrayList s;
	s.top = -1;
	return s;
}

bool isEmpty(StackArrayList s){
	return s.top == -1;
}

bool isFull(StackArrayList s){
	return s.top == MAX - 1;
}

bool stack_push(StackArrayList *s, int elem){
	if (isFull(*s)){
		printf("STACK IS FULL!\n",elem);
		return false;
	}
	s->data[++(s->top)] = elem;
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
