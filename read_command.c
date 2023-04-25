#include "shell.h"

/**
 * read_command -> reads a command
 *
 * Return: Command
*/

char *read_command(void)
{
	char *line = NULL;
	size_t line_size = 0;

	if (getline(&line, &line_size, stdin) == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
