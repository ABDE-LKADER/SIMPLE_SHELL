#include "shell.h"

/**
 * exit_func -> Exit Function
 * 
 * @args: Arguments
 */

void exit_func(char **args)
{
    int i = 0;

    if (!args[1])
        exit(0);
    while (args[1][i])
    {
        if (args[1][i] < '0' || args[1][i] > '9')
        {
            perror("hsh");
            return;
        }
        i++;
    }
    exit(_atoi(args[1]));
}
