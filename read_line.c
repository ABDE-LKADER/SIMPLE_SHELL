#include "shell.h"

/**
 * read_line -> Read a line from stdin
 *
 * Return: Line
*/

char *read_line(void)
{
	char *line = NULL;
	ssize_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}
