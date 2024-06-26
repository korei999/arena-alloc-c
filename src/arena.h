#pragma once

#include <stdlib.h>

#define ARENA_1K 1024
#define ARENA_1M (ARENA_1K * ARENA_1K)

typedef struct Arena
{
    size_t size;
    size_t cap;
    void* pData;
} Arena;

static inline Arena
ArenaCreate(size_t n)
{
    return (Arena) {
        .size = 0,
        .cap = n,
        .pData = malloc(n)
    };
}

static inline void
ArenaFree(Arena* a)
{
    free(a->pData);
}

static inline void
ArenaReset(Arena* a)
{
    a->size = 0;
}

static inline void*
ArenaAlloc(Arena* a, size_t size)
{
    size_t idx = a->size;
    a->size += size;
    return &a->pData[idx];
}
