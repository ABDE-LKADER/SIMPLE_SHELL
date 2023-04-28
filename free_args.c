#include "shell.h"

/**
 * free_args -> Free Arguments
 *
 * @args: Arguments
 */

void free_args(char **args)
{
	int i = 0;

	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
