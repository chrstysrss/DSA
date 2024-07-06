#include "BST.h"
#include "Queue.h"

int main() {
    NodePtr root = NULL;
    init(&root);

	printf("~Trees~\n");
    Product p1 = {"Apple", 10.50, 20, {2024, 7, 15}};
    Product p2 = {"Mango", 8.75, 15, {2024, 9, 5}};
    Product p3 = {"Banana", 12.99, 35, {2024, 8, 10}};
    Product p4 = {"Date", 6.50, 40, {2024, 10, 20}};
    Product p5 = {"Cherry", 5.25, 25, {2024, 6, 10}};
    Product p6 = {"Melon", 4.50, 50, {2025, 1, 1}};
    Product p7 = {"Avocado", 7.30, 30, {2024, 11, 25}};
    Product p8 = {"Grape", 3.75, 45, {2024, 12, 31}};
    Product p9 = {"Honeydew", 9.20, 25, {2025, 2, 14}};
    Product p10 = {"Kiwi", 2.50, 20, {2025, 3, 3}};

    insert(&root, p1);
    insert(&root, p2);
    insert(&root, p3);
    insert(&root, p4);
    insert(&root, p5);
    insert(&root, p6);
    insert(&root, p7);
    insert(&root, p8);
    insert(&root, p9);
    insert(&root, p10);
    
	printf("------------------------------------------------------------------------------------------------------------------------\n");
    printf("Breadth-First Search: ");
    BFS(root);
    printf("\n");
    
	printf("\nIn-order: ");
    inOrder(root);
    printf("\n");

    printf("\nPre-order: ");
    preOrder(root);
    printf("\n");

    printf("\nPost-order: ");
    postOrder(root);
    printf("\n");

    printf("\n------------------------------------------------------------------------------------------------------------------------\n");
    delProd(&root);
        
	printf("\n-------------------------------------------------Ater Deletion----------------------------------------------------------\n");
	printf("Breadth-First Search:");
    BFS(root);
    printf("\n");
    
    printf("\nIn-order: ");
    inOrder(root);
    printf("\n");
    
    printf("\nPre-order: ");
    preOrder(root);
    printf("\n");
    
    printf("\nPost-order: ");
    postOrder(root);
    printf("\n");

    return 0;
}