#include "logs.h"
#include "arena.h"

#include <string.h>
#include <stdalign.h>

int
main()
{
    Arena a = ArenaCreate(ARENA_4K);

    const char* s0 = "what9999";
    const char* s1 = "is";
    const char* s2 = "this";

    /* s1 will concatenate with s0 because no room for null char */
    char* sc0 = ArenaAlloc(&a, 8);
    char* sc1 = ArenaAlloc(&a, 4);
    char* sc2 = ArenaAlloc(&a, 4);

    strncpy(sc0, s0, strlen(s0) + 1);
    strncpy(sc1, s1, strlen(s1) + 1);
    strncpy(sc2, s2, strlen(s2) + 1);

    COUT("sc0: '{}'\nsc1: '{}'\nsc2: '{}'\n", sc0, sc1, sc2);
    ArenaReset(&a);
    COUT("\n");

    sc1 = ArenaAlloc(&a, 2000);
    sc2 = ArenaAlloc(&a, ARENA_1K);

    strncpy(sc1, s1, strlen(s1) + 1);
    strncpy(sc2, s2, strlen(s2) + 1);

    COUT("sc0: '{}'\nsc1: '{}'\nsc2: '{}'\n", sc0, sc1, sc2);

    ArenaClean(&a);
}
