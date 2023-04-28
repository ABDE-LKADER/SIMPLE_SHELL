#include "shell.h"

/**
 * get_func -> Get Function
 * 
 * @args: Arguments
 */

void (*get_func(char **args))(char **)
{
	int i = 0;
	builtin_t builtins[] = {
		{"exit", exit_func},
		{"env", env_func},
		{"setenv", setenv_func},
		{"unsetenv", unsetenv_func},
		{"cd", cd_func},
		{NULL, NULL}
	};

	while (builtins[i].name)
	{
		if (_strcmp(args[0], builtins[i].name) == 0)
			return (builtins[i].func);
		i++;
	}
	return (NULL);
}
