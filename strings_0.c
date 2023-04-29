#include "shell.h"

/**
 * *_strchr -> Locate character in string
 *
 * @s: String
 * @c: Character
 *
 * Return: Depend Condition
 */

char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (s + i);
	}
	return ('\0');
}

/**
 * *_strcpy -> Copy String From Source Into Destinse
 *
 * @dest: Empty Input
 * @src: Input Source
 *
 * Return: Destinse String
 */

char *_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen -> The length of a string
 *
 * @s: Input
 *
 * Return: i String Length
 */

int _strlen(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		continue;
	}
	return (i);
}

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

/**
 * _strcmp ->  Compares two strings
 *
 * @s1: First Input
 * @s2: Second Input
 *
 * Return: 0 Or Different (Condition)
 */

int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}
