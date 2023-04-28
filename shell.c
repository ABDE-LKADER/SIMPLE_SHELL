#include "shell.h"

/**
 * main -> Entry point
 *
 * Return: 0
*/

int main(void)
{
	char *input = NULL, **args = NULL;
	size_t size = 0;
	ssize_t in_len = 0;
	struct stat st;
	list_path *list = NULL;

	check_terminal();
	signal(SIGINT, handle_signal);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		in_len = get_input(&input, &size);
		if (in_len == EOF)
			handle_eof(in_len, input);
		if (in_len == 1)
		{
			free(input);
			continue;
		}
		args = split_input(input, " \n\t\r");
		if (!args)
		{
			free(input);
			continue;
		}
		if (stat(args[0], &st) == 0)
			execute_command(args);
		else
		{
			list = link_path(get_env("PATH"));
			execute_command(args);
			free_list(list);
		}
		free_args(args);
		free(input);
	}
	return (0);
}
