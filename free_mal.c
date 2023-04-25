#include "shell.h"

/**
 * free_mal -> frees mallocs
 *
 * @args: Array Arguments
 * @command: Command
 */

void free_mal(char **args, char *command)
{
	free(args);
	free(command);
}
