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
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, DELIM);
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
		bufsize += MAXARGS;
		tokens = realloc(tokens, bufsize * sizeof(char *));
		if (!tokens)
		{
			fprintf(stderr, "allocation error\n");
			exit(EXIT_FAILURE);
		}
		}
		token = strtok(NULL, DELIM);
	} tokens[position] = NULL;
	return (tokens);
}
