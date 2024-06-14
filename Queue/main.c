#include <stdio.h>
#include <stdlib.h>
#include "MyQueue.h"

int main() {
    Queue q;
    initQueue(&q);

    enQueue(&q, 1);
    enQueue(&q, 2);
    enQueue(&q, 3);
	displayQueue(&q);
	
    printf("Front Element: %d\n", Front(&q));
    printf("Rear Element: %d\n", Rear(&q));
	
    deQueue(&q);
    displayQueue(&q);
    printf("Updated Front Element: %d\n", Front(&q));


    return 0;
}