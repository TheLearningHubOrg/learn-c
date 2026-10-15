#ifndef ROADMAP_H
#define ROADMAP_H

#include <stdbool.h>
#include <stddef.h>

typedef struct {
    int stage_number;
    const char *title;
    const char *domain_focus;
    bool completed;
} RoadmapStage;

#define TOTAL_STAGES 7

const RoadmapStage *get_curriculum_stages(void);
size_t get_completed_stage_count(void);
int calculate_progress_percentage(void);

#endif /* ROADMAP_H */
