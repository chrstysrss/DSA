#include <stdio.h>
#include <stdlib.h>
#include "Hash.h"

int main() {
    Dictionary d;
    int size = CURRENT_SIZE;
    int cnt = 0;
    initDict(&d, size);
    
    printf("~Open Hashing (Separate Chaining)~\n");
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
    del(d, "apple", size);
    printf("Searching for apple: ");
    search(d, "apple", size);
    display(d, size);
    
    printf("\n");
    
    reHash(&d, &size, &cnt); 
    display(d, size);
	
    printf("Insert new elements:\n");
    insert(&d, "watermelon", &size, &cnt);
    insert(&d, "kiwi", &size, &cnt);
    insert(&d, "mango", &size, &cnt);
    insert(&d, "strawberry", &size, &cnt);
    insert(&d, "guava", &size, &cnt);
    insert(&d, "lemon", &size, &cnt);
    insert(&d, "lychee", &size, &cnt);
	display(d, size);
    
    for (int i = 0; i < size; i++) {
        nodePtr curr = d[i];
        while (curr != NULL) {
            nodePtr temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(d);
    
    return 0;
}