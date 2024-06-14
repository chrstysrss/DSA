#ifndef STACK_LINKEDLIST
#define STACK_LINKEDLIST
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} StackLinkedList;

void initStack(StackLinkedList *s);
StackLinkedList createStack();

bool isEmpty(StackLinkedList *s);
bool stack_push(StackLinkedList *s, int elem);
bool stack_pop(StackLinkedList *s);
int stack_peek(StackLinkedList *s);

void display(StackLinkedList *s);
void visualize(StackLinkedList *s);

StackLinkedList getEvens(StackLinkedList *s);
void displayEvens(StackLinkedList *s);

#endif
