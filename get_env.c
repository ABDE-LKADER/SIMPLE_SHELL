#include "shell.h"

/**
 * get_env -> Get Environment
 * 
 * @name: Name
 * 
 * Return: Environment
 */

char *get_env(char *name)
{
    int i = 0, j = 0;
    char *env = NULL;

    while (environ[i])
    {
        while (environ[i][j] == name[j])
            j++;
        if (environ[i][j] == '=')
        {
            env = environ[i] + j + 1;
            return (env);
        }
        i++;
        j = 0;
    }
    return (NULL);
}
