#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"


void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;
}

void enQueue(Queue *q, int n){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	if (newNode == NULL){
		printf("Memory not allocated");
	}
	newNode -> data = n;
	newNode->next = NULL;
    
    if (q->rear == NULL) {
        q->front = newNode;
        q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

void deQueue(Queue *q){
	if (q->front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    NodePtr temp = q->front;
    q->front = q->front->next;

    if (q->front == NULL) {
        q->rear = NULL;
    }

    free(temp);
}

int Front(Queue *q){
	return (q->front !=NULL) ? q->front->data : -1;
} 

int Rear(Queue *q){
	return (q->front !=NULL) ? q->rear->data : -1;
}

bool isEmpty(Queue *q){
	return (q->rear == NULL) ? true : false;

}

void displayQueue(Queue *q) {
    NodePtr curr = q->front;
    if (curr == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    while (curr != NULL) {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}