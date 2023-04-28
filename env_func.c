#include "shell.h"

/**
 * env_func -> Env Function
 * 
 * @args: Arguments
 */

void env_func(char **args)
{
    int i = 0;

    if (!args[1])
    {
        while (environ[i])
        {
            write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
            write(STDOUT_FILENO, "\n", 1);
            i++;
        }
    }
    else
        perror("hsh");
}
