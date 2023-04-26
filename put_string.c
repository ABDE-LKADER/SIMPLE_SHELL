#include "shell.h"

/**
 * put_string -> Print a string
 *
 * @str: String to print
*/

void put_string(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		write(1, &str[i], 1);
}
