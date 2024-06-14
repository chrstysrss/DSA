#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"


void initQueue(Queue *q){
	q->front = NULL;
	q->rear = NULL;
}

void enQueue(Queue *q, int n){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	if (newNode == NUll){
		printf("Memory not allocated");
	}
	temp -> data = n;
}
 
void deQueue(Queue *q){
	
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
