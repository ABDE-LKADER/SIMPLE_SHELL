#include "shell.h"

/**
 * main -> Entry point
 *
 * Return: 0
*/

int main(void)
{
	char *input = NULL, *path = NULL, *command = NULL, **args = NULL;
	size_t in_size = 0;
	ssize_t in_len = 0;
	list_path *list = NULL;
	void (*command_func)(char **);

	signal(SIGINT, handle_signal);
	while (in_len != EOF)
	{
		check_terminal();
		in_len = get_input(&input, &in_size);
		handle_eof(in_len, input);
		args = split_input(input, " \n");
		if (!args || !args[0])
			execute_command(args);
		else
		{
			path = get_env("PATH");
			list = link_path(path);
			command = find_command(args[0], list);
			command_func = get_func(args);
			if (command_func)
			{
				free(input);
				command_func(args);
			}
			else if (!command)
				execute_command(args);
			else if (command)
			{
				free(args[0]);
				args[0] = command;
				execute_command(args);
			}
		}
	} free_list(list);
	free_args(args);
	free(input);
	return (0);
}
