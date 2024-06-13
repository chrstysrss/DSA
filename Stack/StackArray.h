#ifndef STACK_ARRAY
#define TOP -1

typedef struct {
	int data [MAX];
	int count;
} StaticArrayList;

bool isEmpty(StackArrayList s);
bool isFull(StackArrayList s);

void initStack(StackArrayList *s);
StackArrayList createStack();

bool stack_push(StackArrayList *s, int elem);
bool stack_pop(StackArrayList *s);
int stack_peek(StackArrayList s);

void display(StackArrayList s);
void visualize(StackArrayList s);

// others
// create a function that would get all even numbers and retur as a
// new stack removing from the old stack

#endif
