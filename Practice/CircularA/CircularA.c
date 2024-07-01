#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQ;

void initQueue(CircularQ *q) {
	q->front = -1;
	q->rear = -1;
	for(int i = 0; i < MAX; ++i){
		q->data[i] = 0; 
	}
}

bool isFull(CircularQ q){
	return (q.rear + 2) % MAX == q.front;
}

bool isEmpty(CircularQ q){
	return (q.rear + 1) % MAX == q.front;
}

void enQueue(CircularQ *q, int elem) {
	if(isFull(*q)){
		printf("full\n");
		return;
	}
	q->rear = (q->rear + 1) % MAX;
	q->data[q->rear] = elem;
	
	if(q->front == -1){
		q->front = q->rear;
	}
}

void deQueue(CircularQ *q) {
	if(isEmpty(*q)){
		printf("empty");
		return;
	}
	q->front=(q->front+1) % MAX;
	
}

int Front(CircularQ q) {
	return q.data[q.front];
}

int Rear(CircularQ q) {
	return q.data[q.rear];
}

void displayQueue(CircularQ q) {
	printf("Queue Elements:\n");
	int i = q.front;
	
	while(i != q.rear + 1){
		printf("  %d\n", q.data[i]);
		i = (i + 1) % MAX;
	}
}

int main() {
  CircularQ q;
  initQueue(&q);
  
  enQueue(&q, 1);
  enQueue(&q, 2);
  enQueue(&q, 3);
  enQueue(&q, 4);
  enQueue(&q, 5);


  printf("~Current Queue~\n");
  displayQueue(q);

  deQueue(&q);
  deQueue(&q);

  printf("\n~Updated Queue~\n");
  displayQueue(q);

  printf("\n~Enqueue Again~");

  enQueue(&q, 6);
  enQueue(&q, 7);

  printf("\n~Updated Queue~\n");
  displayQueue(q);
  
  printf("\n");
  
  printf("Front element: %d\n", Front(q));
  printf("Rear element: %d\n", Rear(q));

  return 0;
}