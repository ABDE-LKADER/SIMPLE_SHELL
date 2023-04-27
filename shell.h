#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define PROMPT "#cisfun$ "
#define MAX_INPUT 1024

void print_prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute_command(char **args);
void free_args(char **args);

#endif
