#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "myqueue.h"

void resize(Queue *q){
  // [3] to do code logic here ...
    q->capacity += 1;
    q->data = (int *) realloc(q->data, q->capacity * sizeof(int));
}

// Function to enqueue an element
bool enqueue(Queue* q, int element) {
    // [1] to do code logic here ...
    if(isFull (*q)){
        resize(q);
    }
    if(isEmpty((*q))){
        q->front = 0;
    }
        q->data[q->rear++] = element;

    return true;
}

// Function to get the front element
int front(Queue q) {
  // [2] to do code logic here ...
    return q.data[q.front];
}

int main() {
    int choice, elem, val,temp;
    Queue *q=init();

    do {
        printf("Enter operation (1-Enqueue, 2-Dequeue, 0-Exit): ");
        scanf("%d", &choice);
        switch(choice) {
            case 0:
                break;
            case 1:
                printf("Enter item to add: ");
                scanf("%d", &elem);
                // [4] Insert your code logic here ...
                if (enqueue(q, elem))
                    printf("Success adding %d.\n", elem);
                else
                    printf("Error adding %d.\n", elem);

                break;
            case 2:
                // [5] Insert your code logic here ...
                temp = front(*q);
                if (dequeue(q)) 
                    printf("Success removing %d.\n", temp);
                else
                    printf("Error removing %d.\n", temp);

                break;
            default:
                printf("Invalid.\n");
        }
    } while(choice != 0);
    
    q->rear -= 1;
    
    visualize(*q);

    return 0;
}