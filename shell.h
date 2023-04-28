#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

extern char **environ;

char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
int _atoi(char *s);

/**
 * list_path -> Struct To Store Path
 * @dir: Directory
 * @next: Pointer To Next Node
 */

typedef struct list_path
{
    char *dir;
    struct list_path *next;
} list_path;

void cd_func(char **args);
void setenv_func(char **args);
void unsetenv_func(char **args);
void env_func(char **args);
void exit_func(char **args);


/**
 * builtin_t -> Struct To Store Builtins
 * @name: Name
 * @func: Function
 */

typedef struct builtin
{
    char *name;
    void (*func)(char **);
} builtin_t;

void handle_signal(int sig);
void check_terminal(void);
ssize_t get_input(char **input, size_t *size);
void handle_eof(ssize_t in_len, char *input);
char **split_input(char *input, char *delim);
char *get_env(char *var);
list_path *link_path(char *path);
char *find_command(char *command, list_path *list);
void (*get_func(char **args))(char **);
void execute_command(char **args);
void free_list(list_path *list);
void free_args(char **args);

#endif
