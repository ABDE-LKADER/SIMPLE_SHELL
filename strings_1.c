#include "shell.h"

/**
 * _putchar -> Writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: On success 1.
*/

int _putchar(char c)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(1, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}

/**
 * _puts -> Prints a string
 *
 * @str: Input
 */

void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
}

/**
 * _isalpha -> checks for a alphabetic character
 *
 * @c: Character Of _isalpha
 *
 * Return: 1 and 0 (Condition)
 */

int _isalpha(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	else if (c >= 'A' &&  c <= 'Z')
	{
		return (1);
	}
	else
		return (0);
}

/**
 * *_strncpy -> Copy Number Of String From Source Into Destinse
 *
 * @dest: Empty Input
 * @src: Input Source
 * @n: Input Number
 *
 * Return: Destinse String
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

/**
 * *_strncat -> Appends Selected Number Elements src string to the dest string
 *
 * @dest: Destination Input
 * @src: Source Input
 * @n: Number Elements
 *
 * Return: Destination
 */

char *_strncat(char *dest, char *src, int n)
{
	int i;
	int j;

	i = _strlen(dest);
	for (j = 0; dest[j] != '\0' && j < n; j++)
	{
		dest[i] = src[j];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
