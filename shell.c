#include "shell.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, 1 on failure
 */

int main(void)
{
	char *line;
	char **args;
	int status;

	signal(SIGINT, handler);

	do {
		printf(PROMPT);
		line = read_line();
		args = split_line(line);
		status = shell(args);
		free(line);
		free(args);
	} while (status);

	return (EXIT_SUCCESS);
}
