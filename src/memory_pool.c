#include "memory_pool.h"
#include <stdlib.h>

#define ALIGNMENT 8
#define ALIGN_UP(size) (((size) + (ALIGNMENT - 1)) & ~(ALIGNMENT - 1))

MemoryArena arena_create(size_t capacity) {
    MemoryArena arena;
    arena.capacity = capacity;
    arena.offset = 0;
    arena.buffer = (uint8_t *)malloc(capacity);
    return arena;
}

void *arena_alloc(MemoryArena *arena, size_t size) {
    size_t aligned_size = ALIGN_UP(size);
    if (arena->offset + aligned_size > arena->capacity) {
        return NULL; // Out of arena memory
    }
    void *ptr = &arena->buffer[arena->offset];
    arena->offset += aligned_size;
    return ptr;
}

void arena_reset(MemoryArena *arena) {
    arena->offset = 0;
}

void arena_free(MemoryArena *arena) {
    if (arena->buffer) {
        free(arena->buffer);
        arena->buffer = NULL;
    }
    arena->capacity = 0;
    arena->offset = 0;
}
