#include "shell.h"

int main(int argc, char *argv[]) {
	char* line;
	char** tokens;
	int status;

	if (argc == 2) {
		// If a file is provided, read commands from file
		FILE *fp = fopen(argv[1], "r");
		if (fp == NULL) {
			perror("Failed to open file");
			exit(EXIT_FAILURE);
		}

		while ((line = fgets(line, MAX_INPUT_SIZE, fp)) != NULL) {
			tokens = token_size(line);
			execute(tokens);
			free(line);
			free(tokens);
		}

		fclose(fp);
		exit(EXIT_SUCCESS);
	}

	while (1) {
		// Read input and tokenize it
		line = read_line();
		tokens = token_size(line);

		// Execute command and free memory
		execute(tokens);
		free(line);
		free(tokens);
	}

	return 0;
}
