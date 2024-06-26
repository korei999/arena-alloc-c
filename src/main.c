#include "logs.h"
#include "arena.h"

#include <string.h>

int
main()
{
    auto a = ArenaCreate(ARENA_4K);

    const char* s0 = "what";
    const char* s1 = "is";
    const char* s2 = "this";

    char* sc0 = ArenaAlloc(&a, 4);
    char* sc1 = ArenaAlloc(&a, 4);
    char* sc2 = ArenaAlloc(&a, 4);

    strncpy(sc0, s0, strlen(s0) + 1);
    strncpy(sc1, s1, strlen(s1) + 1);
    strncpy(sc2, s2, strlen(s2) + 1);

    COUT("sc0: '{}'\nsc1: '{}'\nsc2: '{}'\n", sc0, sc1, sc2);

    ArenaClean(&a);
}
