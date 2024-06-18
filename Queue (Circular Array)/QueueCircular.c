#include <stdio.h>
#include <stdlib.h>
#include "QueueCircular.h"

void initQueue(CircularQ *q) {
    q->front = -1;
    q->rear = -1;
    for (int i = 0; i < MAX; i++) {
		q->data[i] = 0;
	}
}

void enQueue(CircularQ *q, int elem) {
  if (isFull(*q)) {
    printf("Queue is full\n");
    return;
  }
  q->rear = (q->rear + 1) % MAX;  
  q->data[q->rear] = elem;
  if (q->front == -1) {
    q->front = q->rear;
  }
}

void deQueue(CircularQ *q) {
  if (isEmpty(*q)) {
    printf("Queue is empty\n");
    return;
  }
  printf("Dequeue element: %d\n", q->data[q->front]);
  q->front = (q->front + 1) % MAX;
}


int Front(CircularQ q) {
    return !isEmpty(q) ? q.data[q.front] : -1;
}

int Rear(CircularQ q) {
    return !isEmpty(q) ? q.data[q.rear] : -1;
}

bool isEmpty(CircularQ q){
	return (q.rear + 1) % MAX == q.front;
}

bool isFull(CircularQ q){
	return (q.rear + 2) % MAX == q.front;
}

void displayQueue(CircularQ q) {
    printf("Queue elements:\n");
    int i = q.front;
    
    for (i; i != (q.rear + 1) % MAX; i = (i + 1) % MAX) {
        printf("   %d \n", q.data[i]);
    }
    printf("\n");
}