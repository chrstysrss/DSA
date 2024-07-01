#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
	int data [MAX];
	int top;
} stackNode;

void initStack(stackNode *s){
	s->top = -1;
}

bool isEmpty(stackNode s){
	return s.top == -1;
}

bool isFull(stackNode s){
	return s.top == MAX - 1;
}

stackNode createStack(){
	stackNode s;
	s.top = -1;
	return s;
}

bool push(stackNode *s, int elem) {
//    if (isFull(*s)) {
//        printf("STACK IS FULL!\n");
//        return false;
//    }
    s->data[++(s->top)] = elem;
    printf("%d pushed\n", elem); 
    return true;
}

bool pop(stackNode *s) {
//    if (isEmpty(*s)) {
//        printf("STACK IS EMPTY!\n");
//        return false;
//    }
    int temp = s->data[s->top];
    s->top--;
    printf("%d popped\n", temp); 
    return true;
}

int peek(stackNode s){
//	if (isEmpty(s)){
//		printf("STACK IS EMPTY!\n");
//		return -1;
//	}
	return s.data[s.top];
}

void display(stackNode s) {
    printf("Display: ");
    for (int i = 0; i <= s.top; i++) {
        printf("%d ", s.data[i]);
    }
    printf("\n");
}

void visualize(stackNode s) {
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

int main() {
    stackNode s;
    initStack(&s); 

    push(&s, 1);
    push(&s, 2);
    push(&s, 3);
	push(&s, 4);
	push(&s, 5);
	
	printf("~Current Stack~\n");
    
    int peekVal = peek(s);
	printf("Top is %d\n", peekVal);
	
    visualize(s);
    display(s);
    
    pop(&s); 
    pop(&s);

    printf("\n~Updated Stack~\n");
    
    int peekVal2 = peek(s);
	printf("Top is %d\n", peekVal2);
	
    visualize(s);
	display(s);

	 
    return 0;
}