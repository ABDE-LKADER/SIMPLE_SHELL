#include "shell.h"

/**
 * re_alloc -> Reallocate memory
 *
 * @ptr: Pointer
 * @size: Size
 *
 * Return: Pointer
*/

char **re_alloc(char **ptr, unsigned int size)
{
	char **new_ptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(size);

	if (new_ptr == NULL)
		return (NULL);

	for (i = 0; i < size; i++)
		new_ptr[i] = ptr[i];

	free(ptr);
	return (new_ptr);
}
