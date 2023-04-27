#include "shell.h"

/**
 * main -> Simple shell
 *
 * Return: Depend Condition
*/

int main(void)
{
	char *line;
	char **args;
	int status;

	do {
		print_prompt();
		line = read_line();
		args = split_line(line);
		status = execute_command(args);
		free(line);
		free_args(args);
	} while (status);

	return (EXIT_SUCCESS);
}
