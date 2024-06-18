#ifndef QUEUECIRCULAR_H
#define QUEUECIRCULAR_H

#include <stdbool.h>

#define MAX 10

typedef struct {
    int data[MAX];
    int front;
    int rear;
} CircularQ;

void initQueue(CircularQ *q);
void enQueue(CircularQ *q, int elem);
void deQueue(CircularQ *q);
int Front(CircularQ q);
int Rear(CircularQ q);
bool isEmpty(CircularQ q);
bool isFull(CircularQ q);
void displayQueue(CircularQ q);

#endif