#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

int main() {
    Dictionary d;
    int size = CURRENT_SIZE;
    int cnt = 0;
    initDict(&d, size);
    
    printf("~Closed Hashing (Linear Probing)~\n");
    printf("\n");
    
    printf("Current Table (size:%d)\n", size);
    insert(&d, "apple", &size, &cnt);
    insert(&d, "banana", &size, &cnt);
    insert(&d, "orange", &size, &cnt);
    insert(&d, "grape", &size, &cnt);
    insert(&d, "pineapple", &size, &cnt);
    
    display(d, size);
    
    printf("Searching for apple: ");
    search(d, "apple", size);
    del(&d, "apple", size);
    printf("Searching for apple: ");
    search(d, "apple", size);
    display(d, size);
    
    printf("\n");
    
    reHash(&d, &size, &cnt);   
    printf("Updated Table (size:%d)\n", size);
    display(d, size);
    printf("\n");
    
    printf("Insert new elements:\n");
    insert(&d, "watermelon", &size, &cnt);
    insert(&d, "kiwi", &size, &cnt);
    insert(&d, "mango", &size, &cnt);
    insert(&d, "strawberry", &size, &cnt);
    insert(&d, "guava", &size, &cnt);
    insert(&d, "lemon", &size, &cnt);
    insert(&d, "lychee", &size, &cnt);
    insert(&d, "cherry", &size, &cnt);
	  
    display(d, size);
    
    free(d);
    
    return 0;
}