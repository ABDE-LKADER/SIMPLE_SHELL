#include "shell.h"

/**
 * setenv_func -> Set Environment
 * 
 * @args: Arguments
 */

void setenv_func(char **args)
{
    char *env = NULL, *var = NULL, *value = NULL;
    int i = 0, j = 0, k = 0;

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
    {
        while (args[1][i])
            i++;
        var = malloc(sizeof(char) * (i + 1));
        if (!var)
        {
            perror("hsh");
            return;
        }
        while (args[1][j] != '=')
        {
            var[j] = args[1][j];
            j++;
        }
        var[j] = '\0';
        if (args[1][j + 1])
        {
            while (args[1][j + 1 + k])
                k++;
            value = malloc(sizeof(char) * (k + 1));
            if (!value)
            {
                perror("hsh");
                free(var);
                return;
            }
            k = 0;
            while (args[1][j + 1 + k])
            {
                value[k] = args[1][j + 1 + k];
                k++;
            }
            value[k] = '\0';
        }
        env = get_env(var);
        if (env)
        {
            free(env);
            env = NULL;
            env = malloc(sizeof(char) * (_strlen(var) + _strlen(value) + 2));
            if (!env)
            {
                perror("hsh");
                free(var);
                free(value);
                return;
            }
            _strcpy(env, var);
            _strcat(env, "=");
            _strcat(env, value);
            if (setenv(var, value, 1) == -1)
            {
                perror("hsh");
                free(var);
                free(value);
                free(env);
                return;
            }
            free(var);
            free(value);
            free(env);
        }
        else
        {
            if (setenv(var, value, 1) == -1)
            {
                perror("hsh");
                free(var);
                free(value);
                return;
            }
            free(var);
            free(value);
        }
    }
}
