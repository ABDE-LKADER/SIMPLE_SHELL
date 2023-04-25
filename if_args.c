#include "shell.h"

/**
 * if_args -> if args
 *
 * @args: Array Arguments
 */

void if_args(char **args)
{
	if (args[0] != NULL)
		execute_command(args);
}
