#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
    int length;
} LinkedList;

Node* createNode();
void displayNodeValue(Node* node);
LinkedList* createLinkedList();

int main() {
    LinkedList* linkedList = createLinkedList();
    printf("Length of linked list: %d\n", linkedList->length);
    printf("Address of head node: %p\nAddress of tail node: %p\n", linkedList->head, linkedList->tail);
    printf("Value of head node: %d\nValue of tail node: %d\n", linkedList->head->data, linkedList->tail->data);
    return 0;
}

Node* createNode() {
    return (Node*)malloc(sizeof(Node));
}

void displayNodeValue(Node* node) {
    printf("Node value: %d\n", node->data);
}

LinkedList* createLinkedList() {
    Node* node = createNode();
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->head = node;
    linkedList->tail = node;
    return linkedList;
}