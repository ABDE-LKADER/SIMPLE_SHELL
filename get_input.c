#include "shell.h"

/**
 * get_input -> Get Input
 *
 * @input: Input
 * @size: Size
 *
 * Return: Length
*/

ssize_t get_input(char **input, size_t *size)
{
	ssize_t in_len = 0;

	in_len = getline(input, size, stdin);
	if (in_len == -1)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		free(*input);
		exit(0);
	}
	return (in_len);
}
