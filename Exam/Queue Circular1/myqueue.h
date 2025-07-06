#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdbool.h>

#define QUEUE_SIZE 6

typedef struct {
    int data[QUEUE_SIZE];
    int front;
    int rear;
} Queue;

// Function to initialize the queue
void initQueue(Queue* q);

// Function to check if the queue is empty
bool isEmpty(Queue q);

// Function to check if the queue is full
bool isFull(Queue q);

// Function to dequeue an element
bool dequeue(Queue* q);

// Function to display the elements in the queue
void visualize(Queue q);

#endif