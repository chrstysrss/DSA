#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myqueue.h"

// Function to enqueue an element
bool enqueue(Queue* q, int element) {
    // [1] to do code logic here ...
    if(isFull (*q))
        return false;

    q->rear = (q->rear + 1) % QUEUE_SIZE;
    q->data[q->rear] = element;
    
    return true;
}

// Function to get the front element
int front(Queue q) {
    // [2] to do code logic here ...
    return q.data[q.front];
}

int main() {
    int choice, elem, val,temp;
    Queue q;
    initQueue(&q);

    do {
        printf("Enter operation (1-Enqueue, 2-Dequeue, 0-Exit): ");
        scanf("%d", &choice);
        switch(choice) {
            case 0:
                break;
            case 1:
                printf("Enter item to add: ");
                scanf("%d", &elem);
                // [3] Insert your code logic here ...
                if (enqueue(&q, elem))
                    printf("Success adding %d.\n", elem);
                else
                    printf("Queue is full.\n");
    
                break;
            case 2:
                // [4] Insert your code logic here ...
                temp = front(q);
                if (dequeue(&q))
                    printf("Success removing %d.\n", temp);
                else
                    printf("Queue is empty.\n");
        
                break;
            default:
                printf("Invalid.\n");
        }
    } while(choice != 0);

    visualize(q);

    return 0;
}