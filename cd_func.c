#include "shell.h"

/**
 * cd_func -> Change Directory
 * 
 * @args: Arguments
 */

void cd_func(char **args)
{
    char *home = NULL, *oldpwd = NULL, *pwd = NULL, *cwd = NULL;
    int i = 0, j = 0;

    home = get_env("HOME");
    oldpwd = get_env("OLDPWD");
    pwd = get_env("PWD");
    cwd = getcwd(NULL, 0);
    if (!args[1])
    {
        while (home[i])
            i++;
        while (pwd[j])
            j++;
        if (i == j)
            chdir(home);
        else
        {
            chdir(home);
            free(home);
            home = getcwd(NULL, 0);
            chdir(pwd);
            chdir(home);
        }
    }
    else if (_strcmp(args[1], "-") == 0)
    {
        if (!oldpwd)
        {
            chdir(home);
            free(home);
            home = getcwd(NULL, 0);
            chdir(pwd);
            chdir(home);
        }
        else
        {
            chdir(oldpwd);
            free(oldpwd);
            oldpwd = getcwd(NULL, 0);
            chdir(pwd);
            chdir(oldpwd);
        }
    }
    else
    {
        if (chdir(args[1]) == -1)
        {
            perror("hsh");
            free(home);
            free(oldpwd);
            free(pwd);
            free(cwd);
            exit(2);
        }
    }
    free(home);
    free(oldpwd);
    free(pwd);
    free(cwd);
}
