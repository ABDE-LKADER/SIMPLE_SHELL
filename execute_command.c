#include "shell.h"

/**
 * execute_command -> execute a command
 *
 * @args: Arguments
 */

void execute_command(char **args)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		return;
	}
	if (child_pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
		{
			perror("Error");
			return;
		}
	}
	else
		wait(&status);
}
