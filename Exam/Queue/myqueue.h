#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stdbool.h>


typedef struct {
    int *data;
    int front;
    int rear;
    int capacity;
} Queue;

// Function to initialize the queue
Queue* init();

// Function to check if the queue is empty
bool isEmpty(Queue q);

// Function to check if the queue is full
bool isFull(Queue q);

// Function to dequeue an element
bool dequeue(Queue* q);

// Function to display the elements in the queue
void visualize(Queue q);

#endif