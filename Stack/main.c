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
	
    printf("~Current Stack~\n");
    
    int peekVal = stack_peek(s);
	printf("Top is %d\n", peekVal);
	
    visualize(s);
    display(s);
	
    stack_pop(&s); 
    stack_pop(&s);

    printf("~Updated Stack~\n");
    
    int peekVal2 = stack_peek(s);
	printf("Top is %d\n", peekVal2);
	
    visualize(s);
	display(s);

	
    return 0;
}
