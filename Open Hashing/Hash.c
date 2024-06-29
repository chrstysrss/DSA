#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initDict(Dictionary *d, int size) {
    *d = (Dictionary)malloc(size * sizeof(nodePtr));
    for (int i = 0; i < size; i++) {
        (*d)[i] = NULL;
    }
}

int hash(String fruits, int size) {
    int hashVal = 0;
    for (int i = 0; fruits[i] != '\0'; i++) {
        hashVal += fruits[i];
    }
    return hashVal % size;
}

void insert(Dictionary *d, String fruits, int *size, int *cnt) {
    int ndx = hash(fruits, *size);
    nodePtr newNode = (nodePtr)malloc(sizeof(Node));
    strcpy(newNode->fruits, fruits);
    newNode->next = NULL;
    
    if ((*d)[ndx] == NULL) {
        (*d)[ndx] = newNode;
    } else {
        nodePtr curr = (*d)[ndx];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    (*cnt)++;
    
    if ((float)(*cnt) / (*size) > LOAD_FACTOR) {
        reHash(d, size, cnt);
    }
}


void del(Dictionary d, String fruits, int size) {
    int ndx = hash(fruits, size);
    nodePtr curr = d[ndx];
    nodePtr prev = NULL;
    
    while (curr != NULL && strcmp(curr->fruits, fruits) != 0) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == NULL) {
        printf("%s not found.\n", fruits);
        return;
    }
    
    if (prev == NULL) {
        d[ndx] = curr->next;
    } else {
        prev->next = curr->next;
    }
    free(curr);
    printf("Delete: %s \n", fruits);
}

void search(Dictionary d, String fruits, int size) {
    int ndx = hash(fruits, size);
    nodePtr curr = d[ndx];
    
    while (curr != NULL && strcmp(curr->fruits, fruits) != 0) {
        curr = curr->next;
    }
    if (curr != NULL) {
        printf("Found %s\n", curr->fruits);
    } else {
        printf("Not found\n");
    }
}

void display(Dictionary d, int size) {
    for (int i = 0; i < size; i++) {
        printf("[%d]: ", i);
        nodePtr curr = d[i];
        while (curr != NULL) {
            printf("%s -> ", curr->fruits);
            curr = curr->next;
        }
        printf("\n");
    }
}


void reHash(Dictionary *d, int *size, int *cnt) {
    int nSize = (*size) * 2;
    Dictionary newD = (Dictionary)malloc(nSize * sizeof(nodePtr));
    
    for (int i = 0; i < nSize; i++) {
        newD[i] = NULL;
    }
    for (int i = 0; i < (*size); i++) {
        nodePtr curr = (*d)[i];
        while (curr != NULL) {
            nodePtr next = curr->next;
            int nIndex = hash(curr->fruits, nSize);
            curr->next = newD[nIndex];
            newD[nIndex] = curr;
            curr = next;
        }
    }
    free(*d);
    *d = newD;
    *size = nSize;
    
    printf("Rehashing... new size is %d.\n", *size);
}