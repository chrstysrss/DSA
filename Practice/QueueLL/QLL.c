#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
	int data;
	struct node *next;
}Node, *NodePtr;

typedef struct{
	NodePtr front;
	NodePtr rear;
}Queue;

void initQueue(Queue *q){
	q->front = 	q->rear = NULL;
}

int Front(Queue *q){
	return q->front->data;
} 

int Rear(Queue *q){
	return q->rear->data;
}

bool isEmpty(Queue *q){
	return q->front == NULL;
}

void enQueue(Queue *q, int n){
	NodePtr temp = malloc(sizeof(Node));
	if (temp == NULL){
		printf("Memory not allocated");
	}
	temp -> data = n;
	temp->next = NULL;
    
    if (q->rear == NULL) {
        q->front = q->rear = temp;
    } else {
        q->rear->next = temp;
        q->rear = temp;
    }
    printf("%d enqueued \n", q->rear->data);
}

void deQueue(Queue *q){
	if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    
    NodePtr temp = q->front;
    q->front = temp->next;
    
	printf("%d dequeued\n", temp->data);
    free(temp);
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

int main() {
    Queue q;
    initQueue(&q);

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
    enQueue(&q, 4);
	displayQueue(&q);
	
    printf("Front Element: %d\n", Front(&q));
    printf("Rear Element: %d\n", Rear(&q));
	
    deQueue(&q);
    displayQueue(&q);
    printf("Updated Front Element: %d\n", Front(&q));

    return 0;
}