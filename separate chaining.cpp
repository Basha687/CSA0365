#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}


void insert(struct Node* hashTable[], int key) {
    int index = key % SIZE;
    struct Node* newNode = createNode(key);
    if (hashTable[index] == NULL) {
        hashTable[index] = newNode;
    } else {
        struct Node* temp = hashTable[index];
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void display(struct Node* hashTable[]) {
    for (int i = 0; i < SIZE; i++) {
        printf("Index %d: ", i);
        struct Node* temp = hashTable[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

int main() {
    
    struct Node* hashTable[SIZE];
    for (int i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }

   
    insert(hashTable, 5);
    insert(hashTable, 15);
    insert(hashTable, 25);
    insert(hashTable, 35);
    insert(hashTable, 45);
    insert(hashTable, 55);
    insert(hashTable, 65);
    insert(hashTable, 75);
    insert(hashTable, 85);
    insert(hashTable, 95);

    display(hashTable);

    return 0;
}
