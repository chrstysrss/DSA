#include <stdio.h>
#include <stdlib.h>
#include "FCFS.h"

int main() {
    int n;
    
    printf("~ First Come First Serve - CPU Scheduling ~");
    
    printf("\n\n");
    
    printf("Number of Processes: ");
    scanf("%d", &n);
    
    Queue *q = initQ();
    
    int i ;
    for (i = 0; i < n; ++i) {
        char id = 'A' + i;
        int at, bt;
        
        printf("\n");
        printf("Process %c\n", id);
        
        printf("AT(%c): ", id);
        scanf("%d", &at);
        
        printf("BT(%c): ", id);
        scanf("%d", &bt);
        
        enqueue(q, id, at, bt);
    }
    
    FCFS(q);
    
    printf("\n");
    
    display(q);
  
    freeQ(q);
    
    return 0;
}