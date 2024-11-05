#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <unistd.h>

#define POOL_SIZE 1024

typedef struct Block {
    struct Block* next;
    struct Block* prev;
    size_t size;
} Block;

void initialise_memory_pool();

Block* free_list = NULL;
void* memory_pool = NULL;

int main() {
    return 0;
}

void initialise_memory_pool() {
    memory_pool = mmap(NULL, POOL_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (memory_pool == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
}