#include <stdio.h>
#include "QueueCircular.h"

#define MAX 10

int main() {
  CircularQ q;
  initQueue(&q);
  
  enQueue(&q, 1);
  enQueue(&q, 2);
  enQueue(&q, 3);
  enQueue(&q, 4);
  enQueue(&q, 5);


  printf("~Current Queue~\n");
  displayQueue(q);

  deQueue(&q);
  deQueue(&q);

  printf("\n~Updated Queue~\n");
  displayQueue(q);

  printf("\n~Enqueue Again~");

  enQueue(&q, 6);
  enQueue(&q, 7);

  printf("\n~Updated Queue~\n");
  displayQueue(q);
  
  printf("\n");
  
  printf("Front element: %d\n", Front(q));
  printf("Rear element: %d\n", Rear(q));

  return 0;
}
