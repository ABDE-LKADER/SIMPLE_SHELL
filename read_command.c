#include "shell.h"

char* read_command()
{
    char* line = NULL;
    size_t line_size = 0;
    if (getline(&line, &line_size, stdin) == -1) {
        free(line);
        return NULL;
    }
    return line;
}
