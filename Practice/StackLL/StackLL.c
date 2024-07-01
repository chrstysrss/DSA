#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    struct Node *next;
} stackList;

void initStack(stackList **head) {
    *head = NULL;
}

bool isEmpty(stackList *head) {
    return head == NULL;
}

bool push(stackList **head, int elem) {
    stackList *temp = malloc(sizeof(stackList));
//    if (temp == NULL) {
//        printf("Memory allocation failed.\n");
//        return false;
//    }
    temp->data = elem;
    temp->next = *head;
    *head = temp;
    
    printf("%d pushed!\n", elem);
    return true;
}

bool pop(stackList **head) {
//    if (isEmpty(*head)) {
//        printf("STACK IS EMPTY!\n");
//        return false;
//    }
    stackList *temp = *head;
    *head = (*head)->next;

    printf("%d popped!\n", temp->data);

    free(temp);
    return true;
}

int peek(stackList *head) {
//    if (isEmpty(head)) {
//        printf("STACK IS EMPTY!\n");
//        return -1;
//    }
    return head->data;
}

void display(stackList *head) {
    if (isEmpty(head)) {
        printf("STACK IS EMPTY!\n");
        return;
    }
    stackList *curr = head;
    printf("Display: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

void visualize(stackList *head) {
    if (isEmpty(head)) {
        printf("STACK EMPTY\n");
        return;
    }
    stackList *curr = head;
    printf("Visualize: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main() {
    stackList *head;
    initStack(&head); 

    push(&head, 1);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    push(&head, 7);
    push(&head, 8);
    
    printf("~Current Stack~\n");
    
    int peekVal = peek(head);
    printf("Top is %d\n", peekVal);
    
    visualize(head);
    display(head);
    
    pop(&head); 
    pop(&head);

    printf("\n~Updated Stack~\n");
    
    int peekVal2 = peek(head);
    printf("Top is %d\n", peekVal2);
    
    visualize(head);
    display(head);

    return 0;
}
