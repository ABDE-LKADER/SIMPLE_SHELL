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

/**
 * struct list_path -> Singly linked list
 * 
 * @path: Path
 * @ptr: Pointer Next Node
*/

typedef struct list_path
{
	char *path;
	struct list_path *ptr;
} list_path;

/**
 * struct mybuild -> Struct of builtins
 * 
 * @name: Builtin Name
 * @func: Builtin Function
*/

typedef struct mybuild
{
	char *name;
	void (*func)(char **);
} mybuild;

#endif
