#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char** parse_command(char* command);
void execute_command(char** args);
char* read_command();
void print_prompt();

#endif