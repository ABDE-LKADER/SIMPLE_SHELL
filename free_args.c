#include "shell.h"

/**
 * free_args - Free args
 *
 * @args: Arguments
 *
 * Return: Nothing
 */

void free_args(char **args)
{
	free(args);
}
