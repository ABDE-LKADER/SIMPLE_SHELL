#include "shell.h"

/**
 * main -> Entry point
 *
 * @argc: Number of arguments
 * @argv: Arguments
 * @envp: Environment
 *
 * Return: EXIT_SUCCESS
*/

int main(int argc, char **argv, char **envp)
{
	shell_loop();
	return (EXIT_SUCCESS);
}
