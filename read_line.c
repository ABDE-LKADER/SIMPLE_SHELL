#include "shell.h"

char* read_line(void)
{
	char* line = NULL;
	size_t size = 0;
	ssize_t bytes_read = getline(&line, &size, stdin);

	if (bytes_read == -1)
    {
		if (feof(stdin))
        {
			exit(EXIT_SUCCESS); // Exit on Ctrl+D
		}
        else
        {
			perror("Failed to read input");
			exit(EXIT_FAILURE);
		}
	}

	return line;
}
