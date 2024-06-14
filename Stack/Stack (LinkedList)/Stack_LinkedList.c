#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Stack_LinkedList.h"

void initStack(StackLinkedList *s) {
    s->top = NULL;
}

StackLinkedList createStack() {
    StackLinkedList s;
    s.top = NULL;
    return s;
}

bool isEmpty(StackLinkedList *s) {
    return s->top == NULL;
}

bool stack_push(StackLinkedList *s, int elem) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return false;
    }
    newNode->data = elem;
    newNode->next = s->top;
    s->top = newNode;
    return true;
}

bool stack_pop(StackLinkedList *s) {
    if (isEmpty(s)) {
        printf("STACK IS EMPTY!\n");
        return false;
    }
    Node *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return true;
}

int stack_peek(StackLinkedList *s) {
    if (isEmpty(s)) {
        printf("STACK IS EMPTY!\n");
        return -1;
    }
    return s->top->data;
}

void display(StackLinkedList *s) {
    if (isEmpty(s)) {
        printf("STACK IS EMPTY!\n");
        return;
    }
    Node *curr = s->top;
    printf("Display: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void visualize(StackLinkedList *s) {
    if (isEmpty(s)) {
        printf("STACK EMPTY\n");
        return;
    }
    Node *curr = s->top;
    printf("Visualize: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

StackLinkedList getEvens(StackLinkedList *s) {
    StackLinkedList evens = createStack();
    StackLinkedList temp = createStack();

    while (!isEmpty(s)) {
        int elem = stack_peek(s);
        stack_pop(s);

        if (elem % 2 == 0) {
            stack_push(&evens, elem);
        } else {
            stack_push(&temp, elem);
        }
    }

    while (!isEmpty(&temp)) {
        stack_push(s, stack_peek(&temp));
        stack_pop(&temp);
    }

    return evens;
}

void displayEvens(StackLinkedList *s) {
    StackLinkedList evens = getEvens(s);

    printf("\n~Even Numbers~\n");
    display(&evens);

    printf("\n~Odd Numbers~\n");
    display(s);
}
