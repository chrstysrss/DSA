#ifndef QUEUE_H
#define QUEUE_H

typedef struct QueueNode {
    NodePtr node;
    struct QueueNode *next;
} QueueNode, *QueueNodePtr;

typedef struct {
    QueueNodePtr front;
    QueueNodePtr rear;
} Queue;

void initQueue(Queue *q);
int isEmpty(Queue q);
void enQueue(Queue *q, NodePtr node);
NodePtr deQueue(Queue *q);
NodePtr front(Queue q);

#endif