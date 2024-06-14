#ifndef QUEUE_LINKEDLIST
#define QUEUE_LINKEDLIST
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue *q);
void enQueue(Queue *q, int data);
void deQueue(Queue *q);
int Front(Queue *q);
int Rear(Queue *q);
bool isEmpty(Queue *q);
void displayQueue(Queue *q);

#endif
//Enqueue
//Dequeue
//Front - displays front node
//Rear - displays rear node
//isEmpty