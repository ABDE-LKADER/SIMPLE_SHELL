#include "shell.h"

/**
 * handle_signal -> Handle Signal
 * 
 * @sig: Signal
*/

void handle_signal(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}
