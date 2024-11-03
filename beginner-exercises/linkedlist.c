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

Node* createNode();
Node* createNodeWithData(int data);
void displayNodeValue(Node* node);
LinkedList* createLinkedList();
void appendNode(int data, LinkedList* linkedList);

int main() {
    LinkedList* linkedList = createLinkedList();
    printf("Length of linked list: %d\n", linkedList->length);
    printf("Address of head node: %p\nAddress of tail node: %p\n", linkedList->head, linkedList->tail);
    printf("Value of head node: %d\nValue of tail node: %d\n", linkedList->head->data, linkedList->tail->data);
    appendNode(5, linkedList);
    printf("Address of head node: %p\nAddress of tail node: %p\n", linkedList->head, linkedList->tail);
    printf("Value of head node: %d\nValue of tail node: %d\n", linkedList->head->data, linkedList->tail->data);
    return 0;
}

Node* createNode() {
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = NULL;
    return node;
}

Node* createNodeWithData(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

void displayNodeValue(Node* node) {
    printf("Node value: %d\n", node->data);
}

LinkedList* createLinkedList() {
    Node* node = createNode();
    LinkedList* linkedList = (LinkedList*)malloc(sizeof(LinkedList));
    linkedList->head = node;
    linkedList->tail = node;
    linkedList->appendNode = appendNode;
    return linkedList;
}

void appendNode(int data, LinkedList* linkedList) {
    linkedList->tail->next = createNodeWithData(data);
    linkedList->tail = linkedList->tail->next;
    linkedList->length += 1;
}