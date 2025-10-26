#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure of a memory block
typedef struct Block {
    size_t size;
    bool is_free;
    struct Block* prev;
    struct Block* next;
    void* data;
} Block;

// Head of the doubly linked list
Block* head = NULL;

// Create a new block
Block* create_block(size_t size) {
    Block* new_block = (Block*)malloc(sizeof(Block));
    new_block->size = size;
    new_block->is_free = false;
    new_block->prev = NULL;
    new_block->next = NULL;
    new_block->data = malloc(size);
    return new_block;
}

// Allocate memory using first-fit algorithm
void* allocate(size_t size) {
    Block* temp = head;

    // First-fit search
    while (temp != NULL) {
        if (temp->is_free && temp->size >= size) {
            temp->is_free = false;
            return temp->data;
        }
        temp = temp->next;
    }

    // No suitable free block found, create a new one
    Block* new_block = create_block(size);

    if (head == NULL) {
        head = new_block;
    } else {
        temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new_block;
        new_block->prev = temp;
    }

    return new_block->data;
}

// Free a block of memory
void deallocate(void* ptr) {
    Block* temp = head;
    while (temp != NULL) {
        if (temp->data == ptr) {
            temp->is_free = true;
            printf("Memory block of size %zu deallocated.\n", temp->size);
            return;
        }
        temp = temp->next;
    }
    printf("Pointer not found.\n");
}

// Garbage Collector: Coalesce adjacent free blocks
void garbage_collect() {
    Block* temp = head;
    while (temp != NULL && temp->next != NULL) {
        if (temp->is_free && temp->next->is_free) {
            Block* next_block = temp->next;
            temp->size += next_block->size;
            temp->next = next_block->next;
            if (next_block->next != NULL) {
                next_block->next->prev = temp;
            }
            free(next_block->data);
            free(next_block);
            printf("Garbage collector merged free blocks.\n");
        } else {
            temp = temp->next;
        }
    }
}

// Display memory blocks
void display_blocks() {
    Block* temp = head;
    int i = 0;
    printf("\nMemory Blocks:\n");
    while (temp != NULL) {
        printf("Block %d: Size = %zu, %s\n", ++i, temp->size, temp->is_free ? "Free" : "Allocated");
        temp = temp->next;
    }
}

int main() {
    void* p1 = allocate(100);
    void* p2 = allocate(200);
    void* p3 = allocate(150);

    display_blocks();

    deallocate(p2);
    deallocate(p3);

    display_blocks();

    garbage_collect();

    display_blocks();

    return 0;
}
