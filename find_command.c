#include "shell.h"

/**
 * find_command -> Find Command
 * 
 * @command: Command
 * @list: List
 * 
 * Return: Command
 */

char *find_command(char *command, list_path *list)
{
	char *path = NULL, *command_path = NULL;
	struct stat st;
	list_path *tmp = NULL;

	if (command[0] == '/')
	{
		if (stat(command, &st) == 0)
			return (command);
	}
	else
	{
		tmp = list;
		while (tmp)
		{
			path = _strcat(tmp->dir, "/");
			command_path = _strcat(path, command);
			if (stat(command_path, &st) == 0)
			{
				free(path);
				return (command_path);
			}
			free(path);
			free(command_path);
			tmp = tmp->next;
		}
	}
	return (NULL);
}
