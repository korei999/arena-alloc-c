#include "logs.h"
#include "arena.h"

#include <string.h>

int
main()
{
    Arena a = ArenaCreate(ARENA_1K);

    char* buff = ArenaAlloc(&a, 100);
    const char* what = "hwat";
    strcpy(buff, what);
    COUT("buff: '{}'\n", buff);

    char* buff2 = ArenaAlloc(&a, 100);
    const char* what2 = "asdf";
    strcpy(buff2, what2);
    COUT("buff2: '{}'\n", buff2);

    ArenaFree(&a);
}
