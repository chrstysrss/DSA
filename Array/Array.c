#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char fName[20];
    char lName[20];
} studName;

typedef struct {
    int month;
    int year;
} bday;

typedef struct {
    studName name;
    bday birthdate;
    int age;
    int idNum;
} studentInfo;

typedef struct {
    studentInfo studArray[20];
    int studCount;
} classRecord;

void insertAtFront(classRecord *record, studentInfo student) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    for (int i = record->studCount; i > 0; i--) {
        record->studArray[i] = record->studArray[i - 1];
    }
    record->studArray[0] = student;
    record->studCount++;
}

void insertAtRear(classRecord *record, studentInfo student) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    record->studArray[record->studCount] = student;
    record->studCount++;
}

void insertAtLocation(classRecord *record, studentInfo student, int location) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    if (location < 0 || location > record->studCount) {
        printf("Invalid location.\n");
        return;
    }
    for (int i = record->studCount; i > location; i--) {
        record->studArray[i] = record->studArray[i - 1];
    }
    record->studArray[location] = student;
    record->studCount++;
}

void insertSortedByAge(classRecord *record, studentInfo student) {
    if (record->studCount >= 20) {
        printf("Class is full.\n");
        return;
    }
    int i;
    for (i = record->studCount - 1; i >= 0 && record->studArray[i].age > student.age; i--) {
        record->studArray[i + 1] = record->studArray[i];
    }
    record->studArray[i + 1] = student;
    record->studCount++;
}

void deleteAtFront(classRecord *record) {
    if (record->studCount == 0) {
        printf("Class is empty.\n");
        return;
    }
    for (int i = 0; i < record->studCount - 1; i++) {
        record->studArray[i] = record->studArray[i + 1];
    }
    record->studCount--;
}

void deleteAtRear(classRecord *record) {
    if (record->studCount == 0) {
        printf("Class is empty.\n");
        return;
    }
    record->studCount--;
}

void deleteAtLocation(classRecord *record, int location) {
    if (record->studCount == 0) {
        printf("Class is empty.\n");
        return;
    }
    if (location < 0 || location >= record->studCount) {
        printf("Invalid location.\n");
        return;
    }
    for (int i = location; i < record->studCount - 1; i++) {
        record->studArray[i] = record->studArray[i + 1];
    }
    record->studCount--;
}

void printClassRecord(classRecord *record) {
    for (int i = 0; i < record->studCount; i++) {
        studentInfo student = record->studArray[i];
        printf("Student %d: %s %s, Birthdate: %d/%d, Age: %d, ID: %d\n",
            i + 1, student.name.fName, student.name.lName, student.birthdate.month, student.birthdate.year, student.age,  student.idNum);
    }
}

int main(void) {
    classRecord myClass = { .studCount = 0 };
    
    studentInfo stud1 = { {"Xerxes", "Cuyos"}, {12, 2001}, 22, 101 };
    studentInfo stud2 = { {"Marie", "Sao"}, {3, 2006}, 19, 102 };
    studentInfo stud3 = { {"Victoria", "Dawn"}, {6, 2001}, 22, 103 };
    
    insertAtFront(&myClass, stud1);
    insertAtRear(&myClass, stud2);
    insertAtLocation(&myClass, stud3, 0);
    
    printf("Current class record:\n");
    printClassRecord(&myClass);
    
    deleteAtFront(&myClass);
    printf("\nDeleted record at front:\n");
    printClassRecord(&myClass);
    
    deleteAtRear(&myClass);
    printf("\nDeleted record at rear:\n");
    printClassRecord(&myClass);
    
    return 0;
}
