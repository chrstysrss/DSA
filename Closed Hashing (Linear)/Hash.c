#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"

void initDict(Dictionary *d, int size) {
    *d = (Dictionary)malloc(size * sizeof(String));
    for (int i = 0; i < size; i++) {
        (*d)[i][0] = '\0';
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
    int originalNdx = ndx;
    while ((*d)[ndx][0] != '\0' && strcmp((*d)[ndx], DELETED_NODE) != 0) {
        ndx = (ndx + 1) % (*size);
        if (ndx == originalNdx) {
            printf("Error: Hash table is full\n");
            return;
        }
    }
    strcpy((*d)[ndx], fruits);
    (*cnt)++;
    
    if ((float)(*cnt) / (*size) > LOAD_FACTOR) {
        reHash(d, size, cnt);
    }
}

void del(Dictionary *d, String fruits, int size) {
    int ndx = hash(fruits, size);
    int originalNdx = ndx;
    while ((*d)[ndx][0] != '\0') {
        if (strcmp((*d)[ndx], fruits) == 0) {
            strcpy((*d)[ndx], DELETED_NODE);
            printf("Deleted: %s\n", fruits);
            return;
        }
        ndx = (ndx + 1) % size;
        if (ndx == originalNdx) {
            printf("%s not found.\n", fruits);
            return;
        }
    }
    printf("%s not found.\n", fruits);
}

void search(Dictionary d, String fruits, int size) {
    int ndx = hash(fruits, size);
    int origNdx = ndx;
    while (d[ndx][0] != '\0') {
        if (strcmp(d[ndx], fruits) == 0) {
            printf("Found %s\n", d[ndx]);
            return;
        }
        ndx = (ndx + 1) % size;
        if (ndx == origNdx) {
            break;
        }
    }
    printf("Not found\n");
}

void display(Dictionary d, int size) {
    for (int i = 0; i < size; i++) {
        if (d[i][0] == '\0') {
            printf("[%d]: \n", i);
        } else if (strcmp(d[i], DELETED_NODE) == 0) {
            printf("[%d]: DELETED\n", i);
        } else {
            printf("[%d]: %s\n", i, d[i]);
        }
    }
}

void reHash(Dictionary *d, int *size, int *cnt) {
    int nSize = (*size) * 2;
    Dictionary newD;
    initDict(&newD, nSize);
    *cnt = 0;
    
    for (int i = 0; i < *size; i++) {
        if ((*d)[i][0] != '\0' && strcmp((*d)[i], DELETED_NODE) != 0) {
            insert(&newD, (*d)[i], &nSize, cnt);
        }
    }
    free(*d);
    *d = newD;
    *size = nSize;
    
    printf("Rehashing... new size is %d.\n", *size);
}