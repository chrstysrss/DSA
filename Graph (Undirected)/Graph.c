#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

Graph* createGraph(int num) {
    Graph* g = (Graph*)malloc(sizeof(Graph));
    g->num = num;

    g->array = (List*)malloc(num * sizeof(List));

    for (int i = 0; i < num; ++i) {
        g->array[i].head = NULL;
    }
    
    for (int i = 0; i < num; ++i) {
        for (int x = 0; x < num; ++x) {
            g->Matrix[i][x] = 0;
        }
    }

    return g;
}

void initGraph(Graph* g, int num) {
    for (int i = 0; i < num; ++i) {
        g->array[i].head = NULL;
    }
    for (int i = 0; i < num; ++i) {
        for (int x = 0; x < num; ++x) {
            g->Matrix[i][x] = 0;
        }
    }
}

ListNode* newListNode(Vertex end) {
    ListNode* newNode = (ListNode*)malloc(sizeof(ListNode));
    
    newNode->end = end;
    newNode->next = NULL;
    
    return newNode;
}

void addEdge(Graph* g, Vertex start, Vertex end) {
    ListNode* newNode = newListNode(end);
    newNode->next = g->array[start].head;
    g->array[start].head = newNode;

    newNode = newListNode(start);
    newNode->next = g->array[end].head;
    g->array[end].head = newNode;

    g->Matrix[start][end] = g->Matrix[end][start] = 1;
}

void displayMatrix(Graph* g) {
    printf("Adjacency Matrix:\n");
    printf("   ");
    for (int i = 0; i < g->num; ++i) {
        printf(" %c", 'A' + i);
    }
    printf("\n");
    for (int i = 0; i < g->num; ++i) {
        printf(" %c ", 'A' + i);
        for (int x = 0; x < g->num; ++x) {
            printf(" %d", g->Matrix[i][x]);
        }
        printf("\n");
    }
}

void displayList(Graph* g) {
	printf("\nAdjacency List:\n");
    for (int i = 0; i < g->num; ++i) {
        ListNode* temp = g->array[i].head;
        printf("%c: ", 'A' + i);
        while (temp) {
            printf("%c ", 'A' + temp->end);
            temp = temp->next;
        }
        printf("\n");
    }
}