#include "shell.h"

char** parse_command(char* command)
{
    char** args = malloc(sizeof(char*) * BUFFER_SIZE);
    char* arg = strtok(command, " \t\n");
    int i = 0;
    while (arg != NULL)
	{
        args[i++] = arg;
        arg = strtok(NULL, " \t\n");
    }
    args[i] = NULL;
    return args;
}
