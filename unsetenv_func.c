#include "shell.h"

/**
 * unsetenv_func -> Unset Environment
 * 
 * @args: Arguments
 */

void unsetenv_func(char **args)
{
    int i = 0, j = 0, k = 0, l = 0, m = 0;
    char *env = NULL, *name = NULL, *value = NULL, *newenv = NULL;

    if (!args[1])
    {
        perror("hsh");
        return;
    }
    while (args[i])
        i++;
    if (i > 2)
    {
        perror("hsh");
        return;
    }
    while (args[1][j])
        j++;
    while (environ[k])
        k++;
    while (environ[l])
    {
        while (environ[l][m] == args[1][m])
            m++;
        if (environ[l][m] == '=')
        {
            name = environ[l];
            value = environ[l] + m + 1;
            break;
        }
        l++;
        m = 0;
    }
    if (!name)
    {
        perror("hsh");
        return;
    }
    if (j == m)
    {
        while (environ[l])
        {
            environ[l] = environ[l + 1];
            l++;
        }
    }
    else
    {
        newenv = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
        if (!newenv)
        {
            perror("hsh");
            return;
        }
        _strcpy(newenv, name);
        _strcat(newenv, "=");
        _strcat(newenv, value);
        while (environ[l])
        {
            if (_strcmp(environ[l], newenv) == 0)
            {
                while (environ[l])
                {
                    environ[l] = environ[l + 1];
                    l++;
                }
                break;
            }
            l++;
        }
        free(newenv);
    }
}
