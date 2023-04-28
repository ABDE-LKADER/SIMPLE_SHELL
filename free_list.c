#include "shell.h"

/**
 * free_list -> Free List
 *
 * @list: List
 */

void free_list(list_path *list)
{
	list_path *tmp = NULL;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp->dir);
		free(tmp);
	}
}
