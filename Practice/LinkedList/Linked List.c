#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[20];
    int idNum;
    int age;
} studentInfo;

typedef struct node {
    studentInfo studentData;
    struct node *next;
} Node, *NodePtr;

NodePtr insertAtFront(NodePtr head, studentInfo student) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Failed to allocate memory\n");
        return head;
    }
    newNode->studentData = student;
    newNode->next = head;
    return newNode;
}

void insertAtRear(NodePtr *head, studentInfo data) {
    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->studentData = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        NodePtr temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void insertAtLocation(NodePtr *head, studentInfo data, int position) {
    if (position < 0) {
        printf("Invalid position\n");
        return;
    }

    NodePtr newNode = (NodePtr)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->studentData = data;

    if (position == 0) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    NodePtr temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtFront(NodePtr *head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }
    NodePtr temp = *head;
    *head = (*head)->next;
    free(temp);
}

void deleteAtRear(NodePtr *head) {
    if (*head == NULL) {
        printf("List is empty\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        return;
    }

    NodePtr temp = *head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;
}

void deleteAtLocation(NodePtr *head, int position) {
    if (*head == NULL || position < 0) {
        printf("List is empty or invalid position\n");
        return;
    }

    if (position == 0) {
        NodePtr temp = *head;
        *head = (*head)->next;
        free(temp);
        return;
    }

    NodePtr temp = *head;
    for (int i = 0; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    NodePtr toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
}

void printClassRecord(NodePtr head) {
    NodePtr curr = head;
    while (curr != NULL) {
        printf("Name: %s, ID: %d, Age: %d\n", curr->studentData.name, curr->studentData.idNum, curr->studentData.age);
        curr = curr->next;
    }
}

int main(void) {
    NodePtr head = NULL;

    studentInfo stud1 = { "Xerxes Cuyos", 1001, 22 };
    studentInfo stud2 = { "Marie Sao", 1002, 19 };
    studentInfo stud3 = { "Victoria Dawn", 1003, 12 };


    head = insertAtFront(head, stud1);
	insertAtRear(&head, stud2);
    insertAtLocation(&head, stud3, 1);
    
    printf("Current class record:\n");
    printClassRecord(head);
    
    deleteAtFront(&head);
    printf("\nDeleted record at front:\n");
    printClassRecord(head);
    
    deleteAtRear(&head);
    printf("\nDeleted record at rear:\n");
    printClassRecord(head);

    return 0;
}