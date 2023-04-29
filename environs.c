#include "shell.h"

/**
 * get_environ -> Get the environment as an array of strings
 *
 * @info: Pointer
 *
 * Return: Depend Condition
 */

char **get_environ(info_t *info)
{
	if (!info->environ || info->env_changed)
	{
		info->environ = list_to_strings(info->env);
		info->env_changed = 0;
	}

	return (info->environ);
}

/**
 * unset_env -> Remove an environment variable
 *
 * @info: Pointer
 * @var: Pointer
 *
 * Return: Depend Condition
 */

int unset_env(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * set_env -> Set an environment variable
 *
 * @info: Pointer
 * @var: Pointer
 * @value: Pointer
 *
 * Return: Depend Condition
 */

int set_env(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strcat(buf, "=");
	_strcat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	end_node(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}


/**
 * env_list -> Creates a linked list of the environment
 *
 * @info: Pointer
 *
 * Return: Depend Condition
 */

int env_list(info_t *info)
{
	list_t *node = NULL;
	size_t i;

	for (i = 0; environ[i]; i++)
		end_node(&node, environ[i], 0);
	info->env = node;
	return (0);
}

/**
 * replace_string -> Replace a string with another
 *
 * @old: Pointer
 * @new: Pointer
 *
 * Return: Depend Condition
 */

int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
