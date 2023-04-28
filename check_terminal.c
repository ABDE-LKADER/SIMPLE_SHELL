#include "shell.h"

/**
 * check_terminal -> Check If Terminal
 */

void check_terminal(void)
{
	if (!isatty(STDIN_FILENO))
	{
		perror("Not a terminal");
		exit(1);
	}
}
