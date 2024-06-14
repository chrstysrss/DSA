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

void printList(NodePtr head) {
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
    head = insertAtFront(head, stud2);
    head = insertAtFront(head, stud3);

    printf("List of students:\n");
    printList(head);

    return 0;
}