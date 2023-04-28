#include "shell.h"

/**
 * link_path -> Link Path
 * 
 * @path: Path
 * 
 * Return: List
 */

list_path *link_path(char *path)
{
	list_path *list = NULL, *node = NULL;
	char *token = NULL;

	token = strtok(path, ":");
	while (token)
	{
		node = malloc(sizeof(list_path));
		if (!node)
			return (NULL);
		node->dir = token;
		node->next = list;
		list = node;
		token = strtok(NULL, ":");
	}
	return (list);
}
