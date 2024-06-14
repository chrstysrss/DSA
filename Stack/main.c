#include <stdio.h>
#include "StackArray.h"
#include <stdbool.h>

int main() {
    StackArrayList s;
    initStack(&s); 

    stack_push(&s, 1);
    stack_push(&s, 2);
    stack_push(&s, 3);
	stack_push(&s, 4);
	stack_push(&s, 5);
    stack_push(&s, 6);
    stack_push(&s, 7);
	stack_push(&s, 8);
	
	printf("~Current Stack~\n");
    
    int peekVal = stack_peek(s);
	printf("Top is %d\n", peekVal);
	
    visualize(s);
    display(s);
    
    stack_pop(&s); 
    stack_pop(&s);

    printf("\n~Updated Stack~\n");
    
    int peekVal2 = stack_peek(s);
	printf("Top is %d\n", peekVal2);
	
    visualize(s);
	display(s);

	displayEvens(&s);
	 
    return 0;
}
