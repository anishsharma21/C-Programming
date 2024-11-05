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

static void handle_allocate();
static void* my_malloc(int size);
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
            case 'a':
                handle_allocate();
                break;
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

static void handle_allocate() {
    int input_size;
    printf("\nSpace to allocate: ");
    clear_input_buffer();
    if (scanf("%d", &input_size) != 1) {
        fprintf(stderr, "Error: Invalid input. Please enter a valid number.\n");
        printf("\n");
        return;
    }
    if (input_size <= 0) {
        fprintf(stderr, "Error: Size must be a positive number.\n");
        return;
    }
    size_t size = (size_t)input_size;
}

static void* my_malloc(int size) {
    // find free block -> returns pointer
    // sets values of previous and next pointers at the block
    //
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