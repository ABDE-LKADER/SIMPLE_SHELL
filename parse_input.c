#include "shell.h"

/**
 * parse_input -> Parse input
 *
 * @input: Input
 *
 * Return: Arguments
*/

char **parse_input(char *input)
{
	char **args;
	char *token;
	int index = 0;

	args = malloc(sizeof(char *) * MAX_INPUT);
	if (!args)
	{
		perror("malloc");
		exit(EXIT_FAILURE);
	} token = strtok(input, " \n");
	while (token != NULL)
	{
		args[index] = token;
		index++;
		token = strtok(NULL, " \n");
	} args[index] = NULL;
	return (args);
}
