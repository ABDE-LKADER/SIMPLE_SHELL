#include "shell.h"

/**
 * split_line -> Split line
 *
 * @line: Line
 *
 * Return: Tokens
*/

char **split_line(char *line)
{
	char **tokens = NULL;
	char *token = NULL;
	int i = 0;

	tokens = malloc(sizeof(char *) * 2);
	if (tokens == NULL)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	} token = strtok(line, " \n");
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		if (i >= 2)
		{
			tokens = realloc(tokens, sizeof(char *) * (i + 1));
			if (tokens == NULL)
			{
				perror("realloc");
				exit(EXIT_FAILURE);
			}
		} token = strtok(NULL, " \n");
	} tokens[i] = NULL;
	return (tokens);
}
