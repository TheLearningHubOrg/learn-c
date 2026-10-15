#include <stdio.h>
#include <string.h>
#include "roadmap.h"
#include "memory_pool.h"

int main(void) {
    printf("======================================================================\n");
    printf("  Learn C (C17 / C23) Systems Programming Architecture Masterclass\n");
    printf("======================================================================\n\n");

    printf("[Arena Memory Allocator] Initializing 1024-byte contiguous memory arena...\n");
    MemoryArena arena = arena_create(1024);

    char *dynamic_title = (char *)arena_alloc(&arena, 64);
    if (dynamic_title) {
        strcpy(dynamic_title, "High-Performance Systems & Hardware Architecture");
        printf("  Allocated from arena at offset: %zu bytes (Title: \"%s\")\n", arena.offset, dynamic_title);
    }

    printf("\n[Curriculum Progression] 7-Stage Pedagogical Roadmap:\n");
    const RoadmapStage *stages = get_curriculum_stages();

    for (size_t i = 0; i < TOTAL_STAGES; i++) {
        const char *symbol = stages[i].completed ? "[x]" : "[ ]";
        printf("  %s Stage %d: %s\n", symbol, stages[i].stage_number, stages[i].title);
        printf("      Focus: %s\n", stages[i].domain_focus);
    }

    int progress = calculate_progress_percentage();
    printf("\n[Progress Metric] Completed %zu of %d stages (%d%%)\n",
           get_completed_stage_count(), TOTAL_STAGES, progress);

    arena_free(&arena);
    printf("[Arena Cleanup] Arena memory reclaimed losslessly.\n");

    return 0;
}
