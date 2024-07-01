/*------------------------------------------------------------------------------------
 * 	TODO: Implement set formulas on the given array
 *------------------------------------------------------------------------------------*/

#define MAX_CAPACITY 100

#include <stdio.h>
#include <stdlib.h>

/*************************************************** 
*               Function Prototypes               *
**************************************************/

int add(int storage, int n);
void show(int storage);
void checkMissing(int storage);
int removeVal(int storage, int n);
int unionset(int a, int b);
int intersectionset(int a, int b);
int differenceSet(int a, int b);



int main(){
	int setA = 0;
	int setB = 0;
	int newSet;
	
	// TODO: add the numbers 5, 1, 3, 7, and 9 to set A
	setA = add(setA, 5);
    setA = add(setA, 1);
    setA = add(setA, 3);
    setA = add(setA, 7);
    setA = add(setA, 9);
    

	// TODO: add the numbers 3, 4, 7, 6, and 2, 9, and 0 to set B
	// insert code snippet

    setB = add(setB, 3);
    setB = add(setB, 4);
    setB = add(setB, 7);
    setB = add(setB, 6);
    setB = add(setB, 2);
    setB = add(setB, 9);
    setB = add(setB, 0);
    


	// TODO: show values in set A and B
	printf("\nSet A: ");
    show(setA);

	printf("\nSet B: ");
    show(setB);
    printf("\n");
    system("pause");
	// TODO: display all values from 0-9 that are not present in
	// both sets.

	printf("\nChecking missing numbers...");
	printf("\nMissing numbers in Set A: ");
    checkMissing(setA);

	printf("\nMissing numbers in Set B: ");
    checkMissing(setB);
    printf("\n");
    system("pause");
	// TODO: Using variable newSet, display the union, intersection, and difference
	// of sets A and B

    printf("\nUnion of both sets: ");
    newSet = unionset(setA, setB);
    show(newSet);

    printf("\nIntersection of both sets: ");
    newSet = intersectionset(setA, setB);
    show(newSet);

    printf("\nUnique elements in Set A: ");
    newSet = differenceSet(setA, setB);
    show(newSet);

    printf("\nUnique elements in Set B: ");
    newSet = differenceSet(setB, setA);
    show(newSet);
    printf("\n");
    system("pause");

	// TODO: Delete values 1 and 9 in Set A and 3, 0, and 6 in Set B then display the results
	setA = removeVal(setA, 1);
    setA = removeVal(setA, 9);
    setB = removeVal(setB, 3);
    setB = removeVal(setB, 0);
    setB = removeVal(setB, 6);
    
    printf("\nUpdated Storage 1: ");
    show(setA);
	printf("\nUpdated Storage 2: ");
    show(setB);
    printf("\n");
    system("pause");
	return 0;
}

int add(int storage, int n){
	return storage | 1 << n;    
}

void show(int storage){
	int y;
	
	for(y = 0; y < 32; y++){
		if(storage % 2 == 1)
			printf("%d ", y);
				
		storage = storage >> 1;
	}
	
}	

void checkMissing(int storage){
	int flag = 0;
	int y;
	
	for(y=0; y<10; y++){ 
		if(storage % 2 == 0){ 
            printf("%d ", y);
		}	
        storage = storage >> 1;
	}	

}

int removeVal(int storage, int n){
	return storage & ~(1<<n);
}

int unionset(int a, int b){
	return a | b;
}

int intersectionset(int a, int b){
	return a & b;
}

int differenceSet(int a, int b){
	// insert code logic to find the difference 
}