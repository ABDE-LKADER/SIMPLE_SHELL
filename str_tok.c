#include "shell.h"

/**
 * str_tok -> Split a string into tokens
 *
 * @str: String to split
 * @delim: Delimiter
 *
 * Return: Tokens
 */

char *str_tok(char *str, char *delim)
{
	static char *save;
	char *token;
	int i, j;

	if (str == NULL)
		str = save;
	for (i = 0; str[i] != '\0'; i++)
	{
		for (j = 0; delim[j] != '\0'; j++)
		{
			if (str[i] == delim[j])
			{
				str[i] = '\0';
				save = &str[i + 1];
				return (str);
			}
		}
	}
	if (str == save)
		return (NULL);
	token = str;
	save = NULL;
	return (token);
}
