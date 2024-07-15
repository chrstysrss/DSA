#include <stdio.h>
#include <stdlib.h>
#include "Graph.h"

void main() {
    Graph* g = createGraph(MAX);

    addEdge(g, A, B);
    addEdge(g, A, C);
    addEdge(g, A, D);
    addEdge(g, B, C);
    addEdge(g, B, D);
    addEdge(g, B, E);
    addEdge(g, C, D);
    addEdge(g, D, E);

    displayMatrix(g);

    displayList(g);
}