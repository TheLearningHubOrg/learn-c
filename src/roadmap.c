#include "roadmap.h"

static const RoadmapStage STAGES[TOTAL_STAGES] = {
    {1, "Memory Layout & Pointer Arithmetic", "Stack vs Heap, segment layout, memory alignment, pointer arithmetic", true},
    {2, "Structs, Unions & Bitfields", "Memory padding, endianness, packed structs, bitwise operations", true},
    {3, "Dynamic Memory Management & Arenas", "malloc/free internals, memory leaks, custom arena allocators", true},
    {4, "C Preprocessor, Macros & Metaprogramming", "Token pasting, stringification, variadic macros, header guards", false},
    {5, "Concurrency & POSIX pthreads", "Thread lifecycles, mutex locks, condition variables, atomic primitives", false},
    {6, "Systems Programming & Linux Syscalls", "epoll/kqueue, fork/exec, file descriptors, signals, zero-copy sendfile", false},
    {7, "Staff C Systems Architect Handbook", "Valgrind profiling, AddressSanitizer (ASan), kernel module design, hardening", true}
};

const RoadmapStage *get_curriculum_stages(void) {
    return STAGES;
}

size_t get_completed_stage_count(void) {
    size_t count = 0;
    for (size_t i = 0; i < TOTAL_STAGES; i++) {
        if (STAGES[i].completed) {
            count++;
        }
    }
    return count;
}

int calculate_progress_percentage(void) {
    return (int)((get_completed_stage_count() * 100) / TOTAL_STAGES);
}
