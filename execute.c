#include "shell.h"

void execute(char** args) {
	if (args[0] == NULL) {
		return; // Empty command
	}

	if (strcmp(args[0], "exit") == 0) {
		// Handle exit command
		int status = EXIT_SUCCESS;
		if (args[1] != NULL) {
			status = atoi(args[1]);
		}
		exit(status);
	}

	if (strcmp(args[0], "cd") == 0) {
		// Handle cd command
		if (args[1] == NULL) {
			chdir(getenv("HOME"));
		} else if (strcmp(args[1], "-") == 0) {
			chdir(getenv("OLDPWD"));
		} else {
			chdir(args[1]);
		}
		char* pwd = getcwd(NULL, 0);
		setenv("PWD", pwd, 1);
		free(pwd);
		return;
	}

	pid_t pid = fork();
	if (pid == -1) {
		perror("Failed to fork process");
		exit(EXIT_FAILURE);
	}

	if (pid == 0) {
		// Child process
		if (execvp(args[0], args) == -1) {
		   perror("Failed to execute command");
		   exit(EXIT_FAILURE);
		   }
		   exit(EXIT_SUCCESS);
		   } else {
			// Parent process
			int status;
			waitpid(pid, &status, 0);
		}
}
