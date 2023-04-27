#include "shell.h"

/**
 * main -> Main function
 *
 * @argc: Number of arguments
 * @argv: Arguments
 *
 * Return: 0
 */

int main(void)
{
	char *buffer = NULL, *value, *path, **av;
	size_t size = 0;
	ssize_t len = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, sig_handler);
	while (len != EOF)
	{
		_isatty();
		len = getline(&buffer, &size, stdin);
		_EOF(len, buffer);
		av = splitstring(buffer, " \n");
		if (!av || !av[0])
			execute(av);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			path = _which(av[0], head);
			f = checkbuild(av);
			if (f)
			{
				free(buffer);
				f(av);
			}
			else if (!path)
				execute(av);
			else if (path)
			{
				free(av[0]);
				av[0] = path;
				execute(av);
			}
		}
	} free_list(head);
	freeav(av);
	free(buffer);
	return (0);
}
