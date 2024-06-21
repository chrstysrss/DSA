#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"

int main() {
	SET A = {0, 1, 1, 1, 0};
	SET B = {0, 1, 1, 0, 1};
	
	printf("Set A is:");
	display(A);
	
	printf("Set B is:");
	display(B);
	
	printf("The union is: ");
	SET* Union = unionSet(A,B);
	display(*Union);
	
	printf("The intersection is: ");
	SET* Intersection = intersectionSet(A,B);
	display(*Intersection);
	
	
	insertVal(A, 0);
	display(A);
	
	deleteVal(A, 0);
	display(A);
	return 0;
}
