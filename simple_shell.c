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
				char **args = parse_command(command);

				if_args(args);
				free(args);
			}
		} fclose(fp);
		return (EXIT_SUCCESS);
	} while (1)
	{
		print_prompt();
		char *command = read_command();
		char **args = parse_command(command);

		if (command == NULL)
		{
			printf("\n");
			break;
		} if_args(args);
		free_mal(args, command);
	} return (EXIT_SUCCESS);
}
