#include "shell.h"

/**
 * execute -> Execute a command
 *
 * @args: arguments
 *
 * Return: Depend Condition
*/

int execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		if (execvp(args[0], args) == -1)
			perror("shell");
		exit(EXIT_FAILURE);
	} else if (pid < 0)
	{
		perror("shell");
	} else
	{
		do {
		waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	} return 1;
}
