#include "shell.h"

/**
 * split_line -> Split a line into tokens
 *
 * @line: line
 *
 * Return: Tokens
*/

char **split_line(char *line)
{
	int bufsize = MAXARGS, position = 0;
	char **tokens = malloc(bufsize * sizeof(char *));
	char *token;

	if (!tokens)
	{
		put_string("allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = str_tok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += MAXARGS;
			tokens = re_alloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				put_string("allocation error\n");
				exit(EXIT_FAILURE);
			}
		} token = str_tok(NULL, DELIM);
	} tokens[position] = NULL;
	return (tokens);
}
