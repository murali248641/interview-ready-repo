#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define POOL_SIZE 1024

typedef struct BlockHeader {
    size_t size;
    int free;
    struct BlockHeader *next;
} BlockHeader;

typedef struct {
    uint8_t *pool;
    BlockHeader *free_list;
} MemoryPool;

MemoryPool mem_pool;

void init_pool() {
    mem_pool.pool = (uint8_t *)malloc(POOL_SIZE);
    if (!mem_pool.pool) {
        printf("Pool allocation failed!\n");
        exit(1);
    }

    // Initialize one large free block
    mem_pool.free_list = (BlockHeader *)mem_pool.pool;
    mem_pool.free_list->size = POOL_SIZE - sizeof(BlockHeader);
    mem_pool.free_list->free = 1;
    mem_pool.free_list->next = NULL;
}

void *pool_alloc(size_t size) {
    BlockHeader *curr = mem_pool.free_list;

    while (curr) {
        if (curr->free && curr->size >= size) {
            // Split block if too large
            if (curr->size >= size + sizeof(BlockHeader) + 4) {
                BlockHeader *new_block = (BlockHeader *)((uint8_t *)curr + sizeof(BlockHeader) + size);
                new_block->size = curr->size - size - sizeof(BlockHeader);
                new_block->free = 1;
                new_block->next = curr->next;

                curr->size = size;
                curr->next = new_block;
            }

            curr->free = 0;
            return (void *)((uint8_t *)curr + sizeof(BlockHeader));
        }
        curr = curr->next;
    }

    return NULL;  // No sufficient memory
}

void pool_free(void *ptr) {
    if (!ptr) return;

    BlockHeader *block = (BlockHeader *)((uint8_t *)ptr - sizeof(BlockHeader));
    block->free = 1;

    // Coalescing: merge adjacent free blocks
    BlockHeader *curr = mem_pool.free_list;
    while (curr && curr->next) {
        if (curr->free && curr->next->free) {
            curr->size += sizeof(BlockHeader) + curr->next->size;
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
}

void destroy_pool() {
    free(mem_pool.pool);
    mem_pool.pool = NULL;
    mem_pool.free_list = NULL;
}

void print_pool_status() {
    BlockHeader *curr = mem_pool.free_list;
    printf("Pool blocks:\n");
    while (curr) {
        printf("  Block at %p | Size: %zu | Free: %d\n", (void *)curr, curr->size, curr->free);
        curr = curr->next;
    }
}

int main() {
    init_pool();

    void *p1 = pool_alloc(100);
    void *p2 = pool_alloc(200);
    print_pool_status();

    pool_free(p1);
    pool_free(p2);
    print_pool_status();

    destroy_pool();
    return 0;
}
