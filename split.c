#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char** memory;
    int mem_size;
} BetterSplit;

BetterSplit split(char* str, char value) {
    int mem_size = 0, str_len = 0;
    char string[100] = "";
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == value) {
            mem_size++;
        }
    }
    char** memory = (char**)malloc(mem_size * sizeof(char*));
    int section = 0;
    for (int i = 0; i <= strlen(str); i++) {
        if (str[i] == value || str[i] == '\0') {
            memory[section] = strdup(string);
            memset(string, '\0', sizeof(string));
            str_len = 0;
            section++;
        } else {
            string[str_len] = str[i];
            str_len++;
        }
    }
    
    BetterSplit result;
    result.memory = memory;
    result.mem_size = mem_size;
    return result;
}
