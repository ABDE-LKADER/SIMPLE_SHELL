#include "shell.h"

/**
 * handle_eof -> Handle EOF
 *
 * @in_len: Input Length
 * @input: Input
 *
 * Return: Void
 */

void handle_eof(ssize_t in_len, char *input)
{
	if (in_len == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "\n", 1);
		free(input);
		exit(0);
	}
}
