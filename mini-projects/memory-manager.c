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

static void initialise_memory_pool();
static void clear_input_buffer();

static Block* free_list = NULL;
static void* memory_pool = NULL;
static char user_choice;

int main() {
    while (1) {
        printf("Options:\nAllocate (a)\nFree (f)\nDisplay (d)\nQuit (q)\n\n");
        printf("Choose an option: ");
        scanf("%c", &user_choice);

        switch (user_choice) {
            case 'q':
                exit(0);
            default:
                printf("Not quit\n");
                break;
        }

        clear_input_buffer();
        printf("\n");
    }
}

static void initialise_memory_pool() {
    memory_pool = mmap(NULL, POOL_SIZE, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
    if (memory_pool == MAP_FAILED) {
        perror("mmap");
        exit(1);
    }
}

static void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}