#include <stdio.h>
#include <stdlib.h>

typedef struct Block {
    struct Block* next;
    struct Block* prev;
    char name[32];
    int value;
} Block;

int main() {
    return 0;
}