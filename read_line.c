#include "shell.h"

/**
 * read_line -> Read line
 *
 * Return: Depend Condition
 */

char *read_line(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}
