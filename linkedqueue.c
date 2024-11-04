#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedQueue {
    Node* head;
    Node* tail;
    int length;
} LinkedQueue;

LinkedQueue* createLinkedQueue();
Node* createNode(int value);
void enqueue(LinkedQueue* linkedQueue, int value);
Node* dequeue(LinkedQueue* linkedQueue);
Node* peek(LinkedQueue* linkedQueue);
void display(LinkedQueue* linkedQueue);
void clear(LinkedQueue* linkedQueue);

int main() {
}

LinkedQueue* createLinkedQueue() {
    LinkedQueue* linkedQueue = (LinkedQueue*)malloc(sizeof(LinkedQueue));
    linkedQueue->head = NULL;
    linkedQueue->tail = NULL;
    linkedQueue->length = 0;
    return linkedQueue;
}

Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->next = NULL;
    return node;
}

void enqueue(LinkedQueue* linkedQueue, int value) {
    Node* node = createNode(value);
    if (linkedQueue->length == 0) {
        linkedQueue->head = node;
        linkedQueue->tail = node;
        linkedQueue->head->next = node;
    } else {
        linkedQueue->tail->next = node;
        linkedQueue->tail = node;
    }
    linkedQueue->length++;
}

Node* dequeue(LinkedQueue* linkedQueue) {
    Node* head = linkedQueue->head;
    linkedQueue->head = linkedQueue->head->next;
    return head;
}