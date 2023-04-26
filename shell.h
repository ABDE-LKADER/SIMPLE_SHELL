#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>
#include <errno.h>

extern char **environ;

int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
int _strlen(char *str);
char *_strcat(char *dest, char *src);
int _strncmp(char *s1, char *s2, int n);
char *_strchr(char *s, char c);

void free_array(char **arr);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);

char *read_line(void);
char **split_line(char *line, char *delimiter);
void execute(char **args, char **env);
int built_in(char **args, char **env);
void change_dir(char **args, char **env);
void print_env(char **env);
void set_env(char **args, char **env);
void unset_env(char **args, char **env);
void print_alias(char **alias);
void set_alias(char **alias, char **args);
void alias(char **args, char **alias);
void replace_vars(char **args, int *exit_code, pid_t pid);

char *get_env(char *name);
char *_itoa(pid_t pid);
char *_getenv(char *name, char **env);
void _setenv_var(char *name, char *value, char **env);

void sigint_handler(int sig);

#endif
