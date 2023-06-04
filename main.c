#include <stdio.h>
#include <windows.h>
#include "split.c"
int main() {
    BetterSplit result = split("Hello, world! This is a test", ' ');
    for (int i = 0; i <= result.mem_size; i++) {
        printf("Split %d: %s\n", i, result.memory[i]);
        free(result.memory[i]);
    }

    free(result.memory);

    return 0;
}