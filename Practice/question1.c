#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CAPACITY 30
#define EMPTY -1

// TODO: Implement stacks and queues using ADT data types and complete the
// functions to successfully create a restaurant business process

// Stores all ordered food  of a customer inside a linked list
// Implement Stack using Linked List
typedef struct Order{
    char foodName[CAPACITY];
    struct Order *next; 
}Order;

// Each customer has a name and has their own sets 
// of orders in the form of a linked list
typedef struct Customer{
    char customerName[CAPACITY];
    Order *customerOrder;
}Customer;

// Implement queue using arrays
typedef struct QueueList{
    int front;
    int rear;
    Customer *customer;
}QueueList;

// The stack of foods to cock
typedef struct cookingList{
    char foodName[CAPACITY];
    struct cookingList *next;
}cookingList;

/*************************************************** 
*         Function Prototypes for QUEUE           *
**************************************************/
void initqueue(QueueList **List);
int isQueueEmpty(QueueList *list);
void peekQueue(QueueList *list);
void enqueue (QueueList **list, Customer customer);
void dequeue (QueueList **list);

/*************************************************** 
*         Function Prototypes for STACK           *
**************************************************/
void initStack(cookingList **root);
cookingList *newNode(char foodName[]);
int isStackEmpty(cookingList *root);
void peekStack (cookingList *root);
void push(cookingList **root, char *foodOrders[], int numOrders);
void pop (cookingList **root);

/*************************************************** 
*  Function Prototypes for Creating Customer Order*
**************************************************/
Customer createCustomer(char customerName[], char *foodOrders[], int numOrders);
Order *createOrder(char foodName[]);


int main(){
    char *order1[] = {"Beef Steak", "Rice", "Coke"};        
    char *order2[] = {"Mac & Cheese", "Carbonara", "Lasagna", "Sprite"};
    char *order3[] = {"Chicken Poppers", "Cordon Bleu", "Royal"};

    QueueList *customerList;
    cookingList *foodsToCook = NULL;


    initqueue(&customerList);
    dequeue(&customerList);
    system("pause");
    peekQueue(customerList);
    system("pause");
    
    Customer Customer1 = createCustomer("Lorem", order1, sizeof(order1) / sizeof(order1[0]));
    Customer Customer2 = createCustomer("Ipsum", order2, sizeof(order2) / sizeof(order2[0]));
    Customer Customer3 = createCustomer("Dolor", order3, sizeof(order3) / sizeof(order3[0]));
    
    enqueue(&customerList, Customer1);
    system("pause");
    enqueue(&customerList, Customer2);
    system("pause");
    enqueue(&customerList, Customer3);
    system("pause");
    peekQueue(customerList);

    

    // Stacking Section
    peekStack(foodsToCook);
    system("pause");
    push(&foodsToCook, order1, sizeof(order1) / sizeof(order1[0]));
    system("pause");
    peekStack(foodsToCook);
    system("pause");
    printf("=============================\n");
    pop(&foodsToCook);
    pop(&foodsToCook);
    pop(&foodsToCook);
    printf("=============================\n\n");
    system("pause");
    dequeue(&customerList);
    system("pause");
    peekQueue(customerList);
    system("pause");
    push(&foodsToCook, order2, sizeof(order2) / sizeof(order2[0]));
    system("pause");
    peekStack(foodsToCook);
    printf("=============================\n");
    pop(&foodsToCook);
    pop(&foodsToCook);
    printf("=============================\n\n");
    peekStack(foodsToCook);


    system("pause");
}

void initqueue(QueueList **list){
    *list = (QueueList *)malloc(sizeof(QueueList));

    (*list)->front = EMPTY;
    (*list)->rear = EMPTY;
    (*list)->customer = (Customer *) malloc(CAPACITY * sizeof(Customer));
}

int isQueueEmpty(QueueList *list){
    return list->front == EMPTY;
}

void enqueue(QueueList **list, Customer customer) {
    Order *current = customer.customerOrder;
    int queuePosition;

    if((*list)->front == EMPTY){
        (*list)->front = 0;
        queuePosition = 0;
    }
    
    (*list)->customer[++(*list)->rear] = customer;
    queuePosition = (*list)->rear;

    printf("=============================\n");
    printf("Successfully Queued!\n");
    printf("Customer Name: %s\n", (*list)->customer->customerName);
    printf("Position in Queue: %d\n", queuePosition+1);
    printf("Order: \n");
    while(current->next != NULL){
        printf("%s\n", current->foodName);
        current = current->next;
    }

    printf("=============================\n\n");
}

void dequeue(QueueList **list){
    char customerName[30];

    // #1. If queue is empty, print "Queue Underflow!"
    if(isQueueEmpty(*list)){
        printf("=============================\n");
        printf("Queue Underflow!\n");
        printf("=============================\n\n");
        return;
    }

    strcpy(customerName, ((*list)->customer->customerName));
    ++(*list)->front;

    printf("=============================\n");
    printf("Customer Dequeued!\n");
    printf("Customer Name: %s\n", customerName);
    printf("Order Status: Completed\n");
    printf("=============================\n\n");
}

void peekQueue(QueueList *list){
    printf("=============================\n");
    printf("Checking queue list...\n");

    if(isQueueEmpty(list)){
        printf("Queue Underflow!\n");
        printf("=============================\n\n");
        return;
    }

    printf("Front Customer: %s\n", list->customer[list->front].customerName);
    printf("Last Customer: %s\n\n", list->customer[list->rear].customerName);
    
    printf("Current queue:\n");
    int i = list->front;
    do {
        printf("%s\n", list->customer[i].customerName);
        i = (i + 1) % CAPACITY;
    } while (i != (list->rear + 1) % CAPACITY);


    printf("=============================\n\n");
}

Customer createCustomer(char customerName[], char *foodOrders[], int numOrders){
    int i;
    Customer customer;
    strcpy(customer.customerName, customerName);
    customer.customerOrder=NULL;

    for (i = numOrders - 1; i >= 0; i--) {
        Order *newOrder = createOrder(foodOrders[i]);
        newOrder->next = customer.customerOrder;
        customer.customerOrder = newOrder;
    }
    return customer;
}

Order *createOrder(char foodName[]){
    Order *newOrder = (Order *)malloc(sizeof(Order));

    strcpy(newOrder->foodName, foodName);
    newOrder->next = NULL;

    return newOrder;
}

int isStackEmpty(cookingList *root){
    return !root;
}

void peekStack(cookingList *foodsToCook){
    printf("=============================\n");

    printf("Checking next food to cook...\n");
    if(isStackEmpty(foodsToCook)){
        printf("Nothing to Cook!\n");
        printf("=============================\n\n");
        return;
    }
    printf("Next food to cook: %s\n\n", foodsToCook->foodName);
;
    printf("Current stack: \n");
    cookingList *temp2 = foodsToCook;
    while(temp2 != NULL){
        printf("%s\n", temp2->foodName);
        temp2 = temp2->next;
    }
    printf("=============================\n\n");
}

cookingList* newNode(char foodName[]){
    cookingList *temp = (cookingList *) malloc(sizeof(cookingList));
    strcpy(temp->foodName, foodName);
    temp->next = NULL;
}

void push(cookingList **root, char *foodOrders[], int numOrders){
    int i;
    printf("=============================\n");
    printf("Successfully added the ff to cooking list:\n");
    for (i = numOrders-1; i >= 0; i--) {
        cookingList *temp = newNode(foodOrders[i]);
        temp->next = *root;
        *root = temp;
        printf("%s\n", (*root)->foodName);
    }

    printf("=============================\n\n");
}

void pop (cookingList **root){
    if(isStackEmpty(*root)){
        printf("Nothing to pop!\n");
        return;
    }

    cookingList *temp = *root;
    *root = (*root)->next;

    printf("%s popped from cooking stack!\n", temp->foodName);
}