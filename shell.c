#include "shell.h"

int _strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}

	return (i);
}

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}

	return (s1[i] - s2[i]);
}

char *_strdup(char *str)
{
	char *dup = NULL;
	int i = 0, len = 0;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';

	return (dup);
}

int _strlen(char *str)
{
	int i = 0;

	while (str[i])
		i++;

	return (i);
}

char *_strcat(char *dest, char *src)
{
	int i = 0, j = 0, len1 = 0, len2 = 0;
	char *new = NULL;

	len1 = _strlen(dest);
	len2 = _strlen(src);

	new = malloc(sizeof(char) * (len1 + len2 + 1));
	if (new == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	while (dest[i])
	{
		new[i] = dest[i];
		i++;
	}
	while (src[j])
	{
		new[i] = src[j];
		i++;
		j++;
	}
	new[i] = '\0';

	return (new);
}

int _strncmp(char *s1, char *s2, int n)
{
	int i = 0;

	while (s1[i] && s2[i] && i < n)
	{
		if (s1[i] != s2[i])
			break;
		i++;
	}

	if (i == n)
		return (0);

	return (s1[i] - s2[i]);
}

char *_strchr(char *s, char c)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}

	return (NULL);
}

void free_array(char **arr)
{
	int i = 0;

	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *new_ptr = NULL;
	unsigned int i = 0;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(new_size);
		if (new_ptr == NULL)
		{
			perror("Malloc failed");
			exit(EXIT_FAILURE);
		}
		return (new_ptr);
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}

	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	while (i < old_size && i < new_size)
	{
		new_ptr[i] = *((char *)ptr + i);
		i++;
	}

	free(ptr);

	return (new_ptr);
}


/**
 * read_line - reads a line of input from stdin
 *
 * Return: pointer to input string
 */

char *read_line(void)
{
    size_t size = 0;
    char *buffer = NULL;

    if (getline(&buffer, &size, stdin) == -1)
	{
		if (feof(stdin))
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}
		else
		{
			perror("Error reading from stdin");
			exit(EXIT_FAILURE);
		}
	}
	
	return buffer;
}

/**
 * split_line - splits a string into an array of strings
 * @line: string to split
 * @delimiter: delimiter to split string by
 *
 * Return: pointer to array of strings
 */

char **split_line(char *line, char *delimiter)
{
	char **tokens = NULL, *token = NULL;
	int i = 0, size = 0;

	/* Allocate memory for tokens */
	size = _strlen(line);
	tokens = malloc(sizeof(char *) * size);
	if (tokens == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}

	/* Split line into tokens */
	token = strtok(line, delimiter);
	while (token != NULL)
	{
		tokens[i] = token;
		i++;
		token = strtok(NULL, delimiter);
	}
	tokens[i] = NULL;

	return tokens;
}

/**
 * execute - executes a command
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: void
 */

void execute(char **args, char **env)
{
	int i = 0, size = 0;
	char *path = NULL, **path_tokens = NULL;

	/* Check if command is a path */
	if (_strchr(args[0], '/') != NULL)
	{
		if (execve(args[0], args, env) == -1)
			perror(args[0]);
	}
	else
	{
		/* Get PATH variable */
		while (env[i] != NULL)
		{
			if (_strncmp(env[i], "PATH=", 5) == 0)
				path = env[i];
			i++;
		}

		/* Split PATH into tokens */
		path_tokens = split_line(path, "=:");
		size = _strlen(path_tokens[0]);

		/* Concatenate command with each token */
		for (i = 0; path_tokens[i] != NULL; i++)
		{
			path_tokens[i] = _realloc(path_tokens[i], size, size + _strlen(args[0]) + 2);
			_strcat(path_tokens[i], "/");
			_strcat(path_tokens[i], args[0]);
			if (execve(path_tokens[i], args, env) == -1)
				perror(args[0]);
		}
	}
}

/**
 * built_in - checks if command is a built-in
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: 0 if command is a built-in, 1 if not
 */

int built_in(char **args, char **env)
{
	int i = 0, status = 0;
	char *built_ins[] = {"exit", "env", "setenv", "unsetenv", NULL};

	/* Check if command is a built-in */
	while (built_ins[i] != NULL)
	{
		if (_strcmp(args[0], built_ins[i]) == 0)
		{
			status = 1;
			break;
		}
		i++;
	}

	/* Execute built-in command */
	switch (i)
	{
		case 0:
			free_array(args);
			exit(EXIT_SUCCESS);
		case 1:
			print_env(env);
			break;
		case 2:
			set_env(args, env);
			break;
		case 3:
			unset_env(args, env);
			break;
		default:
			break;
	}

	return status;
}

void change_dir(char **args, char **env)
{
	char *home = NULL, *oldpwd = NULL, *pwd = NULL, *cwd = NULL;

	/* Get HOME variable */
	home = _getenv("HOME", env);

	/* Get PWD variable */
	pwd = _getenv("PWD", env);

	/* Get OLDPWD variable */
	oldpwd = _getenv("OLDPWD", env);

	/* Change directory */
	if (args[1] == NULL)
	{
		if (chdir(home) == -1)
			perror("Error changing directory");
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		if (chdir(oldpwd) == -1)
			perror("Error changing directory");
	}
	else
	{
		if (chdir(args[1]) == -1)
			perror("Error changing directory");
	}

	/* Update PWD variable */
	cwd = getcwd(cwd, 0);
	_setenv_var("PWD", cwd, env);

	/* Update OLDPWD variable */
	_setenv_var("OLDPWD", pwd, env);
}

/**
 * _setenv_var - sets an environment variable
 * 
 * @name: name of variable
 * @value: value of variable
 * @env: environment variables
*/

void _setenv_var(char *name, char *value, char **env)
{
	int i = 0, j = 0, size = 0;
	char *var = NULL;

	/* Check if variable name is given */
	if (name == NULL)
		return;

	/* Check if variable exists */
	while (env[i] != NULL)
	{
		/* Get variable name */
		size = _strlen(name);
		var = malloc(sizeof(char) * size);
		if (var == NULL)
		{
			perror("Malloc failed");
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < size; j++)
			var[j] = env[i][j];

		/* Check if variable exists */
		if (_strcmp(var, name) == 0)
		{
			/* Update variable */
			free(env[i]);
			env[i] = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
			if (env[i] == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(env[i], name);
			_strcat(env[i], "=");
			_strcat(env[i], value);
			return;
		}
		i++;
	}

	/* Add new variable */
	env[i] = malloc(sizeof(char) * (_strlen(name) + _strlen(value) + 2));
	if (env[i] == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	_strcpy(env[i], name);
	_strcat(env[i], "=");
	_strcat(env[i], value);
	env[i + 1] = NULL;
}

/**
 * _getenv - get index of environment variable
 * 
 * @name: name of variable
 * @env: environment variables
 * 
 * Return: index of variable, -1 if not found
*/

char *_getenv(char *name, char **env)
{
	int i = 0, j = 0, size = 0;
	char *var = NULL, *value = NULL;

	/* Check if variable name is given */
	if (name == NULL)
		return NULL;

	/* Check if variable exists */
	while (env[i] != NULL)
	{
		/* Get variable name */
		size = _strlen(name);
		var = malloc(sizeof(char) * size);
		if (var == NULL)
		{
			perror("Malloc failed");
			exit(EXIT_FAILURE);
		}
		for (j = 0; j < size; j++)
			var[j] = env[i][j];
		var[j] = '\0';

		/* Check if variable exists */
		if (_strcmp(var, name) == 0)
		{
			/* Get variable value */
			size = _strlen(env[i]) - _strlen(name);
			value = malloc(sizeof(char) * size);
			if (value == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}
			for (j = 0; j < size; j++)
				value[j] = env[i][j + _strlen(name) + 1];
			value[j] = '\0';
			free(var);
			return value;
		}
		free(var);
		i++;
	}

	return NULL;
}

/**
 * print_env - prints environment variables
 * @env: array of environment variables
 *
 * Return: void
 */

void print_env(char **env)
{
	int i = 0;

	while (env[i] != NULL)
	{
		printf("%s\n", env[i]);
		i++;
	}
}

/**
 * _setenv - sets an environment variable
 * @args: array of arguments
 * @env: array of environment variables
 *
 * Return: void
 */

void set_env(char **args, char **env)
{
	int i = 0, j = 0, size = 0;
	char *var = NULL, *value = NULL;

	/* Check if variable name is given */
	if (args[1] == NULL)
	{
		printf("Usage: setenv VARIABLE VALUE\n");
		return;
	}

	/* Check if variable exists */
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], args[1], _strlen(args[1])) == 0)
		{
			/* Update variable */
			size = _strlen(args[1]) + _strlen(args[2]) + 2;
			var = malloc(sizeof(char) * size);
			if (var == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(var, args[1]);
			_strcat(var, "=");
			_strcat(var, args[2]);
			env[i] = var;
			return;
		}
		i++;
	}

	/* Add new variable */
	size = _strlen(args[1]) + _strlen(args[2]) + 2;
	var = malloc(sizeof(char) * size);
	if (var == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	_strcpy(var, args[1]);
	_strcat(var, "=");
	_strcat(var, args[2]);
	env[i] = var;
	env[i + 1] = NULL;
}

void unset_env(char **args, char **env)
{
	int i = 0, j = 0;

	/* Check if variable name is given */
	if (args[1] == NULL)
	{
		printf("Usage: unsetenv VARIABLE\n");
		return;
	}

	/* Check if variable exists */
	while (env[i] != NULL)
	{
		if (_strncmp(env[i], args[1], _strlen(args[1])) == 0)
		{
			/* Delete variable */
			free(env[i]);
			while (env[i + 1] != NULL)
			{
				env[i] = env[i + 1];
				i++;
			}
			env[i] = NULL;
			return;
		}
		i++;
	}
}

void print_alias(char **alias)
{
	int i = 0;

	while (alias[i] != NULL)
	{
		printf("%s\n", alias[i]);
		i++;
	}
}

void set_alias(char **alias, char **args)
{
	int i = 0, j = 0, size = 0;
	char *var = NULL, *value = NULL;

	/* Check if variable name is given */
	if (args[1] == NULL)
	{
		printf("Usage: setalias VARIABLE VALUE\n");
		return;
	}

	/* Check if variable exists */
	while (alias[i] != NULL)
	{
		if (_strncmp(alias[i], args[1], _strlen(args[1])) == 0)
		{
			/* Update variable */
			size = _strlen(args[1]) + _strlen(args[2]) + 2;
			var = malloc(sizeof(char) * size);
			if (var == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(var, args[1]);
			_strcat(var, "=");
			_strcat(var, args[2]);
			alias[i] = var;
			return;
		}
		i++;
	}

	/* Add new variable */
	size = _strlen(args[1]) + _strlen(args[2]) + 2;
	var = malloc(sizeof(char) * size);
	if (var == NULL)
	{
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	_strcpy(var, args[1]);
	_strcat(var, "=");
	_strcat(var, args[2]);
	alias[i] = var;
	alias[i + 1] = NULL;
}

void alias(char **args, char **alias)
{
	int i = 0, j = 0;

	/* Check if variable name is given */
	if (args[1] == NULL)
	{
		printf("Usage: alias VARIABLE\n");
		return;
	}

	/* Check if variable exists */
	while (alias[i] != NULL)
	{
		if (_strncmp(alias[i], args[1], _strlen(args[1])) == 0)
		{
			/* Delete variable */
			free(alias[i]);
			while (alias[i + 1] != NULL)
			{
				alias[i] = alias[i + 1];
				i++;
			}
			alias[i] = NULL;
			return;
		}
		i++;
	}
}

void replace_vars(char **args, int *exit_code, pid_t pid)
{
	int i = 0, j = 0, k = 0, size = 0;
	char *var = NULL, *value = NULL, *pid_str = NULL;

	while (args[i] != NULL)
	{
		/* Check for variable name */
		if (args[i][0] == '$')
		{
			/* Get variable value */
			value = get_env(args[i] + 1);
			if (value == NULL)
			{
				printf("Variable not found\n");
				return;
			}

			/* Replace variable with value */
			size = _strlen(args[i]) + _strlen(value);
			var = malloc(sizeof(char) * size);
			if (var == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(var, value);
			_strcat(var, args[i] + 1);
			args[i] = var;
		}

		/* Check for $$ */
		if (_strcmp(args[i], "$$") == 0)
		{
			/* Get pid value */
			pid_str = _itoa(pid);
			if (pid_str == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}

			/* Replace $$ with pid */
			size = _strlen(args[i]) + _strlen(pid_str);
			var = malloc(sizeof(char) * size);
			if (var == NULL)
			{
				perror("Malloc failed");
				exit(EXIT_FAILURE);
			}
			_strcpy(var, pid_str);
			_strcat(var, args[i] + 2);
			args[i] = var;
		}

		i++;
	}
}

void sigint_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}

/**
 * get_env - get value of environment variable
 * 
 * @name: name of variable
 * 
 * Return: value of variable, NULL if not found
 */

char *get_env(char *name)
{
	int i = 0, j = 0;

	while (environ[i] != NULL)
	{
		while (environ[i][j] == name[j])
		{
			if (environ[i][j + 1] == '=')
				return (environ[i] + j + 2);
			j++;
		}
		i++;
		j = 0;
	}

	return (NULL);
}

/**
 * _itoa - convert integer to string
 * 
 * @pid: pid value
 * 
 * Return: string of pid value
*/

char *_itoa(pid_t pid)
{
	int i = 0, j = 0, size = 0;
	char *str = NULL;

	/* Get size of pid */
	size = 1;
	while (pid / size > 9)
		size *= 10;

	/* Allocate memory for string */
	str = malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);

	/* Convert pid to string */
	while (size > 0)
	{
		str[i] = (pid / size) + '0';
		pid %= size;
		size /= 10;
		i++;
	}
	str[i] = '\0';

	return (str);
}

/**
 * main - entry point for simple shell program
 *
 * Return: 0 on success, non-zero on failure
 */

int main(void)
{
    char *line = NULL;
    char **args = NULL, **env = environ;
    int status = 1, exit_code = 0;
    pid_t pid;

    /* Set up signal handling */
    signal(SIGINT, sigint_handler);

    while (status)
    {
        /* Print prompt and read input */
        printf("Simple_Shell$ ");
        line = read_line();

        /* Split input into arguments */
        args = split_line(line, " \t\n");

        /* Handle variables replacement */
        replace_vars(args, &exit_code, getpid());

        /* Check if input is a built-in command */
        if (built_in(args, env) == 0)
            continue;

        /* Fork process to execute command */
        pid = fork();
        if (pid < 0)
        {
            perror("Fork failed");
            exit(EXIT_FAILURE);
        }
        else if (pid == 0)
        {
            /* Child process */
            execute(args, env);
            /* If execve returns, there was an error */
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
        else
        {
            /* Parent process */
            waitpid(pid, &status, 0);
        }

        /* Free memory */
        free(line);
        free_array(args);

        /* Update exit status */
        if (WIFEXITED(status))
            exit_code = WEXITSTATUS(status);

        /* Print exit status if $? is called */
        if (_strncmp(args[0], "$?", 2) == 0)
            printf("%d\n", exit_code);
    }

    return exit_code;
}
