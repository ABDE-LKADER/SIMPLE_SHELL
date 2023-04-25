#include "shell.h"

/**
 * main -> main function
 *
 * @ac: Arguments count
 * @av: Arguments vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int main(int ac, char **av)
{
	if (ac > 2)
	{
		fprintf(stderr, "Usage: %s [filename]\n", av[0]);
		return (EXIT_FAILURE);
	}
	if (ac == 2)
	{
		char **args = parse_command(command);
		FILE *fp = fopen(av[1], "r");

		if (fp == NULL)
		{
			perror(av[1]);
			return (EXIT_FAILURE);
		} char buffer[BUFFER_SIZE];
		while (fgets(buffer, BUFFER_SIZE, fp) != NULL)
		{
			char *command = strtok(buffer, "#");

			if (command != NULL)
			{
				if (args[0] != NULL)
					execute_command(args);
				free(args);
			}
		} fclose(fp);
		return (EXIT_SUCCESS);
	}
	while (1)
	{
		print_prompt();
		char *command = read_command();

		if (command == NULL)
		{
			printf("\n");
			break;
		} char **args = parse_command(command);
		if (args[0] != NULL)
			execute_command(args);
		free(args);
		free(command);
	} return (EXIT_SUCCESS);
}
