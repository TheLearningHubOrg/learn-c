#ifndef MEMORY_POOL_H
#define MEMORY_POOL_H

#include <stddef.h>
#include <stdint.h>

typedef struct {
    uint8_t *buffer;
    size_t capacity;
    size_t offset;
} MemoryArena;

MemoryArena arena_create(size_t capacity);
void *arena_alloc(MemoryArena *arena, size_t size);
void arena_reset(MemoryArena *arena);
void arena_free(MemoryArena *arena);

#endif /* MEMORY_POOL_H */
