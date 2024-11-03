#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int data;
    struct Node* next;
} Node;

int main() {
    Node* node1 = (Node*)malloc(sizeof(Node));
    node1->data = 3;
    printf("Node value: %d\n", node1->data);
    return 0;
}