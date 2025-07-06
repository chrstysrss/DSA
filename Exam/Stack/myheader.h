#ifndef MYHEADER_H
#define MYHEADER_H

#include <stdbool.h>

// typedef char String[30];

typedef struct {
    int day, month, year;
} Date;

typedef struct {
    char prodName[30];
    float prodPrice;
    Date expDate;
} Product;

typedef struct {
    Product *prodList;
    int max;
    int top;
} Stack, ArrayList;

// Function to create new Date and new Product
Date new_date(int date, int month, int year);
Product new_product(char *prodName, float prodPrice, Date expDate);

// Function to calculate the difference between two dates
int date_diff(Date d1, Date d2);

int compareDates(Date d1, Date d2);

// Stack operations
void initStack(Stack *s, int max);
Stack createStack(int max);
bool push(Stack *s, Product p);
bool pop(Stack *s);
Product peek(Stack s); // returns an empty string for product name if the stack is empty
bool isEmpty(Stack s);
bool isFull(Stack s);
void visualize(Stack s);
Stack populateStack(int n);

#endif