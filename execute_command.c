#include "shell.h"

/**
 * execute_command -> executes a command
 *
 * @args: Array Arguments
*/

void execute_command(char **args)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		execvp(args[0], args);
		perror(args[0]);
		exit(EXIT_FAILURE);
	}
	else
		wait(NULL);
}
