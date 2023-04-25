#include "shell.h"

/**
*/

char** token_size(char* line)
{
	char** tokens = malloc(MAX_NUM_TOKENS * sizeof(char*));
	char* token;
	int num_tokens = 0;

	if (!tokens)
    {
		perror("Failed to allocate memory");
		exit(EXIT_FAILURE);
	}

	token = strtok(line, " \t\n");
	while (token != NULL && num_tokens < MAX_NUM_TOKENS)
    {
		tokens[num_tokens] = token;
		num_tokens++;
		token = strtok(NULL, " \t\n");
	}

	tokens[num_tokens] = NULL;
	return tokens;
}
