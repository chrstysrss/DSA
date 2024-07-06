#include "BST.h"
#include "Queue.h"

void init(NodePtr *root) {
	*root = NULL;
}

NodePtr createNode(Product p) {
    NodePtr newNode = (NodePtr)malloc(sizeof(NodeType));
    newNode->item = p;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int cmp(Product p1, Product p2) {
    return strcmp(p1.prodName, p2.prodName);
}

void insert(NodePtr *root, Product p) {
    if (*root == NULL) {
        *root = createNode(p);
        printf("Inserting %s\n", p.prodName);
    } else if (cmp((*root)->item, p) > 0) {
        insert(&(*root)->left, p);
    } else if (cmp((*root)->item, p) < 0) {
        insert(&(*root)->right, p);
    }
}

void delProd(NodePtr *root) {
    if (*root != NULL) {
        printf("Enter product name to delete: ");
        char prod[20];
        scanf("%s", prod);
		printf("Deleting %s....\n", prod);
		
        NodePtr *trav = root, temp, *trav2;
        while (*trav != NULL && strcmp((*trav)->item.prodName, prod) != 0) {
            if (strcmp((*trav)->item.prodName, prod) > 0)
                trav = &(*trav)->left;
            else
                trav = &(*trav)->right;
        }
        if (*trav != NULL) {
            if ((*trav)->left == NULL) {
                temp = *trav;
                *trav = temp->right;
                free(temp);
            } else if ((*trav)->right == NULL) {
                temp = *trav;
                *trav = temp->left;
                free(temp);
            } else {
                for (trav2 = &(*trav)->right; (*trav2)->left != NULL; trav2 = &(*trav2)->left) {}
                temp = *trav2;
                *trav2 = temp->right;
                (*trav)->item = temp->item;
                free(temp);
            }
            printf("Product %s deleted\n", prod);
        } else {
            printf("Product not found.\n");
        }
    } 
}

void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}

int isEmpty(Queue q) {
    return q.front == NULL;
}

void enQueue(Queue *q, NodePtr node) {
    QueueNodePtr newNode = (QueueNodePtr)malloc(sizeof(QueueNode));
    newNode->node = node;
    newNode->next = NULL;
    if (q->rear == NULL) {
        q->front = q->rear = newNode;
    } else {
        q->rear->next = newNode;
        q->rear = newNode;
    }
}

NodePtr deQueue(Queue *q) {
    if (isEmpty(*q)) {
        return NULL;
    }
    QueueNodePtr temp = q->front;
    NodePtr node = temp->node;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    free(temp);
    return node;
}

NodePtr front(Queue q) {
    if (isEmpty(q)) {
        return NULL;
    }
    return q.front->node;
}

void BFS(NodePtr root) {
    if (root == NULL) 
        return;

    Queue q;
    initQueue(&q);
    enQueue(&q, root);

    while (!isEmpty(q)) {
        NodePtr curr = front(q);
        deQueue(&q);

        printf("|%s| ", curr->item.prodName);

        if (curr->left != NULL)
            enQueue(&q, curr->left);
        if (curr->right != NULL)
            enQueue(&q, curr->right);
    }
}

void inOrder(NodePtr root) {
    if (root == NULL){
    	return;	
	} 
    inOrder(root->left);
    printf("|%s| ", root->item.prodName);
    inOrder(root->right);
}

void preOrder(NodePtr root) {
    if (root == NULL){
    	return;	
	} 
    printf("|%s| ", root->item.prodName);
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(NodePtr root) {
    if (root == NULL) {
    	return;
	}
    postOrder(root->left);
    postOrder(root->right);
    printf("|%s| ", root->item.prodName);
}