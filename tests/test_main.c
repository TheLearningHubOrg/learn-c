#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "roadmap.h"
#include "memory_pool.h"

void test_roadmap_stages(void) {
    const RoadmapStage *stages = get_curriculum_stages();
    assert(stages != NULL);
    assert(stages[0].stage_number == 1);
    assert(stages[6].stage_number == 7);

    size_t completed = get_completed_stage_count();
    assert(completed >= 2);

    int progress = calculate_progress_percentage();
    assert(progress >= 0 && progress <= 100);
    printf("PASS: test_roadmap_stages\n");
}

void test_memory_arena(void) {
    MemoryArena arena = arena_create(256);
    assert(arena.buffer != NULL);
    assert(arena.capacity == 256);
    assert(arena.offset == 0);

    void *ptr1 = arena_alloc(&arena, 32);
    assert(ptr1 != NULL);
    assert(arena.offset >= 32);

    void *ptr2 = arena_alloc(&arena, 64);
    assert(ptr2 != NULL);
    assert(arena.offset >= 96);

    // Test out-of-memory within arena
    void *ptr3 = arena_alloc(&arena, 500);
    assert(ptr3 == NULL);

    arena_reset(&arena);
    assert(arena.offset == 0);

    arena_free(&arena);
    assert(arena.buffer == NULL);
    printf("PASS: test_memory_arena\n");
}

int main(void) {
    printf("Running C Unit Tests...\n");
    test_roadmap_stages();
    test_memory_arena();
    printf("ALL C TESTS PASSED SUCCESSFULLY!\n");
    return 0;
}
