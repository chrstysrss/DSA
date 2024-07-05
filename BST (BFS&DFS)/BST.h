#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int day, month, year;
}Date;

typedef struct {
	char prodName[20];
	float prodPrice;
	int prodQty;
	Date expDate;
}Product;

typedef struct node {
	Product item;
	struct node *left, *right;
}NodeType, *NodePtr;

void init(NodePtr *root);
NodePtr createNode(Product p);
int cmp(Product p1, Product p2);

void insert(NodePtr *root, Product p);
void delProd(NodePtr *root);

void BFS(NodePtr root);
void inOrder(NodePtr root);
void postOrder(NodePtr root);
void preOrder(NodePtr root);

#endif

//add
//delete
//traversal: BFS,DFS(in,post,pre)