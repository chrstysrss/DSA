#ifndef FCFS_H
#define FCFS_H

typedef struct Process {
    char id;
    int at;
    int bt;
    int ct;
    int tt;
    int wt;
    struct Process *next;
} Process;

typedef struct Queue {
    Process *front;
    Process *rear;
    int size;
} Queue;

Queue *initQ();
void enqueue(Queue *q, char id, int at, int bt);
Process *dequeue(Queue *q);
void sortQ(Queue *q);
void FCFS(Queue *q);
void display(Queue *q);
void freeQ(Queue *q);

#endif