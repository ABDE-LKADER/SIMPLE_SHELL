#include "shell.h"

/**
 * split_input -> Split Input
 * 
 * @input: Input
 * @delim: Delimiter
 * 
 * Return: Array
 */

char **split_input(char *input, char *delim)
{
    char **array = NULL;
    char *token = NULL;
    int i = 0;

    array = malloc(sizeof(char *) * 1024);
    if (!array)
        return (NULL);
    token = strtok(input, delim);
    while (token)
    {
        array[i] = token;
        token = strtok(NULL, delim);
        i++;
    }
    array[i] = NULL;
    return (array);
}
