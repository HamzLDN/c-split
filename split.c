#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** memory;
    int mem_size;
} BetterSplit;

BetterSplit split(char* str, char value) {
    int mem_size = 0, str_len = 0;
    int str_size = strlen(str) + 1; // Length of the input string + 1 for null terminator
    char* string = (char*)malloc(str_size * sizeof(char)); // Dynamically allocate memory for 'string'
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == value) {
            mem_size++;
        }
    }

    char** memory = (char**)malloc((mem_size + 1) * sizeof(char*));
    int section = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == value || str[i] == '\0') {
            string[str_len] = '\0'; // Add null terminator to 'string'
            memory[section] = strdup(string);
            memset(string, '\0', str_size);
            str_len = 0;
            section++;
            continue;
        }
        string[str_len] = str[i];
        str_len++;
    }

    free(string);

    BetterSplit result;
    result.memory = memory;
    result.mem_size = mem_size;
    return result;
}
