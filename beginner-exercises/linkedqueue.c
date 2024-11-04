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
int peek(LinkedQueue* linkedQueue);
void display(LinkedQueue* linkedQueue);
void clear(LinkedQueue* linkedQueue);

int main() {
    printf("Initialise linked queue\n");
    LinkedQueue* linkedQueue = createLinkedQueue();
    display(linkedQueue);

    printf("\nEnqueue 3 values\n");
    enqueue(linkedQueue, 1);
    enqueue(linkedQueue, 2);
    enqueue(linkedQueue, 4);
    display(linkedQueue);

    printf("\nDequeue\n");
    Node* removedHead = dequeue(linkedQueue);
    free(removedHead);
    display(linkedQueue);

    printf("\nPeek\n");
    printf("Head value: %d\n", peek(linkedQueue));

    printf("\nClear linked queue\n");
    clear(linkedQueue);
    display(linkedQueue);

    printf("\n");
    return 0;
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
    } else {
        linkedQueue->tail->next = node;
        linkedQueue->tail = node;
    }
    linkedQueue->length++;
}

Node* dequeue(LinkedQueue* linkedQueue) {
    if (linkedQueue->length == 0) {
        return NULL;
    }
    Node* head = linkedQueue->head;
    linkedQueue->head = linkedQueue->head->next;
    linkedQueue->length--;
    if (linkedQueue->length == 0) {
        linkedQueue->tail = NULL;
    }
    return head;
}

int peek(LinkedQueue* linkedQueue) {
    return linkedQueue->head->value;
}

void display(LinkedQueue* linkedQueue) {
    int length = linkedQueue->length;
    if (length == 0) {
        printf("[Empty]\n");
        return;
    }
    Node* curNode = linkedQueue->head;
    for (int i = 0; i < length; i++) {
        if (i == 0)
            printf("(front) %d", curNode->value);
        else
            printf(" <-- %d", curNode->value);
        curNode = curNode->next;
    }
    printf("\n");
}

void clear(LinkedQueue* linkedQueue) {
    int length = linkedQueue->length;
    if (length == 0) {
        printf("\nAlready empty.\n");
    }
    Node* curNode = linkedQueue->head;
    for (int i = 0; i < length; i++) {
        Node* tempNode = curNode->next;
        free(curNode);
        curNode = tempNode;
    }
    linkedQueue->head = NULL;
    linkedQueue->tail = NULL;
    linkedQueue->length = 0;
}