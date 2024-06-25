#include "FCFS.h"
#include <stdio.h>
#include <stdlib.h>

Queue *initQ() {
    Queue *q = malloc(sizeof(Queue));
    if (q == NULL) {
        printf("Memory allocation error\n");
        return NULL;
    }
    q->front = q->rear = NULL;
    q->size = 0; 
    return q;
}

void enqueue(Queue *q, char id, int at, int bt) {
    Process *newProcess = malloc(sizeof(Process));
    if (newProcess == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    *newProcess = (Process){ 
        .id = id,
        .at = at,
        .bt = bt,
        .ct = 0,
        .tt = 0,
        .wt = 0,
        .next = NULL
    };
    
    if (q->rear == NULL) {
        q->front = q->rear = newProcess;
    } else {
        q->rear->next = newProcess;
        q->rear = newProcess;
    }
    q->size++;  
}

Process *dequeue(Queue *q) {
    if (q->front == NULL) {
        return NULL;
    }
    
    Process *dequeued = q->front;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    
    q->size--; 
    return dequeued;
}

void sortQ(Queue *q) {
    if (q == NULL || q->front == NULL) {
        return;
    }
    
    int swap;
    Process *ptr;
    Process *lptr = NULL;
    
    do {
        swap = 0;
        ptr = q->front;
        
        while (ptr->next != lptr) {
            if (ptr->at > ptr->next->at) {
         
                int tempID = ptr->id;
                int tempAT = ptr->at;
                int tempBT = ptr->bt;
                
                ptr->id = ptr->next->id;
                ptr->at = ptr->next->at;
                ptr->bt = ptr->next->bt;
                
                ptr->next->id = tempID;
                ptr->next->at = tempAT;
                ptr->next->bt = tempBT;
                
                swap = 1;
            }
            ptr = ptr->next;
        }
        lptr = ptr;
    } while (swap);
}

void FCFS(Queue *q) {
    int currTime = 0;
    int totalWT = 0;
    int totalTT = 0;

    sortQ(q);
    
    Process *curr = q->front;
    while (curr != NULL) {
        if (currTime < curr->at) {
            currTime = curr->at;
        }

        curr->ct = currTime + curr->bt;
        curr->tt = curr->ct - curr->at;
        curr->wt = curr->tt - curr->bt;
        currTime = curr->ct;
        curr = curr->next;
    }
}

void display(Queue *q) {
    int totalWT = 0;
    int totalTT = 0;
    
    printf("Process | AT | BT | CT | TT | WT\n");
    printf("--------|----|----|----|----|----\n");
    
    Process *curr = q->front;
    while (curr != NULL) {
        printf("   %c    | %2d | %2d | %2d | %2d | %2d\n",
               curr->id, curr->at, curr->bt,
               curr->ct, curr->tt,
               curr->wt);
        
        totalWT += curr->wt;
        totalTT += curr->tt;
        
        curr = curr->next;
    }
    
    printf("--------------------------------\n");
    printf("\n");
    printf("Total TT: %d\n", totalTT);
    printf("Total WT: %d\n", totalWT);
    printf("\n");
    
    if (q->size > 0) {
    	float avgWT = (float)totalWT / q->size;
        printf("Average WT: %.2f\n", avgWT);
        
    	float avgTT = (float)totalTT / q->size;
    	printf("Average TT: %.2f\n", avgTT);      
    } 
}

void freeQ(Queue *q) {
    Process *curr = q->front;
    while (curr != NULL) {
        Process *next = curr->next;
        free(curr);
        curr = next;
    }
    free(q);
}