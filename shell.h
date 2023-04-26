#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <string.h>
#include <fcntl.h>
#include <dirent.h>

#define PROMPT "$ "
#define DELIM " \n\t\r\a"
#define MAXARGS 10
#define MAXPATH 1024

extern char **environ;

char *read_line(void);
char **split_line(char *line);
int execute(char **args);
int launch(char **args);
int cd(char **args);
int setenv_cmd(char **args);
int unsetenv_cmd(char **args);
int printenv(char **args);
int exit_cmd(char **args);
char *replace_vars(char *line);
int handle_operators(char **args, int result);
int handle_semicolon(char **args);
int handle_alias(char **args);
int shell(char **args);
void handler(int signum);

#endif
