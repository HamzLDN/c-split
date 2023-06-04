#include <stdio.h>
#include <windows.h>
#include "split.c"
int main() {
    char file_path[MAX_PATH];
    GetModuleFileName(NULL, file_path, MAX_PATH);
    BetterSplit result = split(file_path, '\\');
    printf("Number of splits: %d\n", result.mem_size);

    for (int i = 0; i <= result.mem_size; i++) {
        printf("Split %d: %s\n", i, result.memory[i]);
        free(result.memory[i]);
    }

    free(result.memory);

    return 0;
}