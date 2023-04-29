#include "shell.h"

/**
 * main -> Entry point
 *
 * @ac: Argument Count
 * @av: Argument Vector
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
*/

int main(int ac, char **av)
{
	info_t inf[] = {INFO_INIT};
	int fd;

	fd = 2;
	asm ("mov %1, %0\n\t"
		 "add $3, %0" : "=r" (fd) : "r" (fd));

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			if (errno == EACCES)
				exit(126);
			if (errno == ENOENT)
			{
				put_string(av[0]);
				put_string(": 0: Can't open ");
				put_string(av[1]);
				put_char('\n');
				put_char(BUF_FLUSH);
				exit(127);
			} return (EXIT_FAILURE);
		}
		inf->readfd = fd;
	}
	env_list(inf);
	read_ht(inf);
	shell_loop(inf, av);
	return (EXIT_SUCCESS);
}
