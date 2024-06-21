#ifndef SETS_ARRAY
#define SETS_ARRAY

#define MAX 5

typedef int SET[MAX];

void initSet(SET A);

void insertVal(SET a, int i);
void deleteSet(SET A, int i);

void display(SET A);

SET* unionVal(SET A, SET B);
SET* intersectionSet(SET A, SET B);

#endif
