#include <stdio.h>
#include <stdlib.h>
#include "Sets.h"

void initSet(SET A){
	int i;
	for(i = 0; i < MAX; i++){
		A[i] = 0;
	}
}

void insertVal(SET A, int i){
	if(i < MAX){
		A[i] = 1;
		printf("inserting success.\n");
	}
}

void deleteVal(SET A, int i){
	if(i < MAX){
		A[i] = 0;
		printf("deleting success.\n");
	}
}

void display (SET A){
	int i;
	for(i = 0; i < MAX; i++){
		printf("%d ", A[i]);
	}
	printf("\n");
}

SET* unionSet(SET A, SET B){
	int i;
	SET *C = (SET*)malloc(sizeof(SET));
	
	if(C != NULL){
		for(i = 0; i < MAX; i++){
			(*C)[i] = A[i] | B[i];
		}
	}
	return C;
}

SET* intersectionSet(SET A, SET B){
	int i;
	SET *C = (SET*)malloc(sizeof(SET));
	
	if(C != NULL){
		for(i = 0; i < MAX; i++){
			(*C)[i] = A[i] & B[i];
		}
	}
	return C;
}
