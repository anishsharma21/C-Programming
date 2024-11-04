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
    void (*appendNode)(int data, struct LinkedList* linkedList);
} LinkedList;

Node* createNode(int data);
LinkedList* createLinkedList();
void appendNode(int data, LinkedList* linkedList);

int main() {
    LinkedList* linkedList = createLinkedList();
    printf("Initial length of linked list: %d\n\n", linkedList->length);
    linkedList->appendNode(1, linkedList);
    printf("Length of linked list: %d\n", linkedList->length);
    printf("Head node value: %d, Tail node value: %d\n", linkedList->head->data, linkedList->tail->data);
    printf("Head node address: %p, Tail node address: %p\n", linkedList->head, linkedList->tail);
    linkedList->appendNode(2, linkedList);
    printf("Length of linked list: %d\n", linkedList->length);
    printf("Head node value: %d, Tail node value: %d\n", linkedList->head->data, linkedList->tail->data);
    printf("Head node address: %p, Tail node address: %p\n", linkedList->head, linkedList->tail);
    return 0;
}

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

LinkedList* createLinkedList() {
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->head = NULL;
    linkedList->tail = NULL;
    linkedList->length = 0;
    linkedList->appendNode = appendNode;
    return linkedList;
}

void appendNode(int data, LinkedList* linkedList) {
    Node* newNode = createNode(data);
    if (linkedList->length == 0) {
        linkedList->head = newNode;
        linkedList->head->next = newNode;
    } else {
        linkedList->tail->next = newNode;
    }
    linkedList->tail = newNode;
    linkedList->length += 1;
}