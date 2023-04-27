#include "shell.h"

/**
 * execute_command -> Execute command
 *
 * @args: Arguments
 *
 * Return: Status Command
*/

int execute_command(char **args)
{
	pid_t pid, wpid;
	int status;

	if (args[0] == NULL)
		return (1);

	pid = fork();
	if (pid == 0)
	{
		if (execve(args[0], args, NULL) == -1)
			perror("execve");
		exit(EXIT_FAILURE);
	} else if (pid < 0)
		perror("fork");
	else
	{
		do {
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	} return 1;
}
