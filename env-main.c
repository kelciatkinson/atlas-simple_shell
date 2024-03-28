#include "shell.h"
void nothing(void);

/**
* main - main entry point for shell
*
* @argc: the count of arguments
* @argv: the arguments
* @env:  the environment things
*
* Return: 0 success -1 error
*
*/

int main(int argc, char **argv, char **env)
{
	char *buffer, *found;

	size_t buffersize = 6235;
	int fork_result;

	char **tokens = NULL;

	int status = 0;

	argc = argc;
	buffer = malloc(sizeof(char) * buffersize);
	if (buffer == NULL)
		return (-1);

	while (prompt(buffer, &buffersize) != -1)
	{
		printf("%s\n", buffer);
		if (_isspace(buffer) != 1)
		{
			if (strncmp(buffer, "exit", 4) == 0)
			{
				free(buffer);
				if (status == -1)
					exit (2);
				return (status);
			}
			printf("we made it to line 42 %s\n", buffer);
			tokens = tokenize(buffer, " \n");
			printf("We made it passed to line 44\n");
			found = findpath(tokens[0], env);
			printf("found is %s and we made it to line 46\n", found);
			if (found == NULL)
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);
			else
			{
				fork_result = fork();
				if (fork_result == -1)
					return (-1);
				if (fork_result == 0)
				{
					if (execve(found, tokens, env) == -1)
						fprintf(stderr, "%s: No such file or directory\n", argv[0]);
					return (0);
				}
				wait(&status);
			}
		}
	}

	free(buffer);
	return (0);
}

/**
* tokenize- make a string into tokens
*
* @str:     the string to tokenize
* @d:       deliminator
*
* Return:   an array of pointes to strings
*
*/

char **tokenize(char *str, char *d)
{
	char *part = NULL;

	char **result;

	int i = 0;

	int j = 0;

	int k = 0;

	while (*str)
	{
		if (*str == d[0])
			i++;
		str++;
		k++;
	}
	i++;

	str -= k;

	result = malloc(sizeof(char *) * (++i));
	if (result == NULL)
		return (NULL);

	part = strtok(str, d);
	printf("this line 107 is not empty %s\n", part);
	while (part)
	{
		result[j++] = strdup(part);
		printf("this loop is part: %s and result: %s\n", part, result[j - 1]);
		part = strtok(NULL, d);
		printf("wait a second, does this work?%s\n", part);
	}
	result[j] = NULL;

	return (result);
}

/**
* prompt-      print a prompt if running in interactive mode.
*              also, get a line and put it into the buffer.
*
* @buffer:     the buffer to put the line into from getline
* @buffersize: how big the buffer is
*
* Return:      the number of bytes read from getline
*/

ssize_t prompt(char *buffer, size_t *buffersize)
{
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	return (getline(&buffer, buffersize, stdin));
}

/**
* _isspace- find out if a string is all spaces.
*
* @str:    the string to check
*
* Return:  1 if all spaces, 0 not all spaces
*/

int _isspace(char *str)
{
	while (*str)
	{
		if (*str != ' ' && *str != '\n' && *str != '\t')
			return (0);
		str++;
	}
	return (1);
}

char *findpath(char *cmd, char **env)
{
	char **patharray = NULL;
	int i = 0;
	char *str;
	struct stat *buff;

	buff = malloc(sizeof(struct stat));

	if (buff == NULL)
	{
		return (NULL);
	}
	printf("Something find path L:169\n");
	patharray = tokenize(get_env("PATH", env), ":");
	printf("it made it past patharry this is line 171\n");
	str = malloc(strlen(patharray[i]) + 1 + strlen(cmd));

	if (str == NULL)
	{
		return (NULL);
	}
	printf("this made it to line 172\n");


	while (patharray[i])
	{
		sprintf(str, "%s/%s", patharray[i], cmd);
		printf("%s\n", str);
		if (stat(str, buff) == 0)
		{
			free_double_pointer(patharray);
			return (str);
		}
		i++;
	}
	free_double_pointer(patharray);
	free(str);
	return (NULL);
}