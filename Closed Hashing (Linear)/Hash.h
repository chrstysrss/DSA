#ifndef HASH_H
#define HASH_H

#define CURRENT_SIZE 10
#define STRING_SIZE 20
#define LOAD_FACTOR 0.65
#define DELETED_NODE "DELETED"

typedef char String[STRING_SIZE];

typedef String* Dictionary;

void initDict(Dictionary *d, int size);
int hash(String fruits, int size);

void insert(Dictionary *d, String fruits, int *size, int *cnt);
void del(Dictionary *d, String fruits, int size);
void search(Dictionary d, String fruits, int size);
void display(Dictionary d, int size);

void reHash(Dictionary *d, int *size, int *cnt);

#endif