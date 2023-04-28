#include "shell.h"

/**
 * *_strcat -> Appends the src string to the dest string
 *
 * @dest: Destination Input
 * @src: Source Input
 *
 * Return: Destination
 */

char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = _strlen(dest);
	for (j = 0; src[j] != '\0'; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
