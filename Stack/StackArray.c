#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "StackArray.h"

void initStack(StackArrayList *s){
	s->top = -1;
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
	if (isEmpty(*s)){
		printf("STACK IS EMPTY!\n");
		return false;
	}
	s->top--;
	return true;
}

int stack_peek(StackArrayList s){
	if (isEmpty(s)){
		printf("STACK IS EMPTY!\n");
		return -1;
	}
	return s.data[s.top];
}

void display(StackArrayList s) {
    StackArrayList tempStack = createStack();
    
    while (!isEmpty(s)) {
        stack_push(&tempStack, stack_peek(s));
        stack_pop(&s);
    }
    
    printf("Display: ");
    while (!isEmpty(tempStack)) {
        int elem = stack_peek(tempStack);
        printf("%d ", elem);
        stack_push(&s, elem); 
        stack_pop(&tempStack);
    }
    printf("\n");
}

void visualize(StackArrayList s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return;
    }
    
    printf("Visualize: ");
    for (int i = s.top; i >= 0; i--) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

StackArrayList getEvens(StackArrayList *s) {
    StackArrayList evens= createStack();
    StackArrayList temp = createStack();

    while (!isEmpty(*s)) {
        int elem = stack_peek(*s);
        stack_pop(s);

        if (elem % 2 == 0) {
            stack_push(&evens, elem);
        } else {
            stack_push(&temp, elem);
        }
    }

    while (!isEmpty(temp)) {
        stack_push(s, stack_peek(temp));
        stack_pop(&temp);
    }

    return evens;
}

void displayEvens(StackArrayList *s) {
    StackArrayList evens = getEvens(s);

    printf("\n~Even Numbers~\n");
    display(evens);

    printf("\n~Odd Numbers~\n");
    display(*s);
}