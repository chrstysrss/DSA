#ifndef GRAPH_H
#define GRAPH_H
#define MAX 5

typedef enum {
    A, B, C, D, E
} Vertex;

typedef struct {
    Vertex end;
    struct ListNode* next;
} ListNode;

typedef struct {
    ListNode* head;
} List;

typedef struct {
    int num;
    List* array;
    int Matrix[MAX][MAX];
} Graph;

Graph* createGraph(int num);
void initGraph(Graph* g, int num);
ListNode* newListNode(Vertex end);
void addEdge(Graph* g, Vertex start, Vertex end);
void displayMatrix(Graph* g);
void displayList(Graph* g);

#endif