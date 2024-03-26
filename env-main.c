#include "shell.h"

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
	char *buffer;
	size_t buffersize = 4096;
	int fork_result;
	char **tokens = NULL;
	int i = 0;

	argc = argc;
	
	buffer = malloc(sizeof(char) * buffersize);
	if (buffer == NULL)
		return (-1);

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buffer, &buffersize, stdin);
		if (strncmp(buffer, "exit", 4) == 0)
			break;

		fork_result = fork();
		if (fork_result == -1)
			return (-1);
		if (fork_result == 0)
		{
			tokens = tokenize(buffer);
			if (execve(tokens[0], tokens, env) == -1)
				fprintf(stderr, "%s: No such file or directory\n", argv[0]);

			return (0);
		}
		wait(NULL);
	}

	free(buffer);

	return (0);
}

/**
 * tokenize- make a string into tokens
 *
 * @str:     the string to tokenize
 *
 * Return:   an array of pointes to strings
 *
 */

char **tokenize(char *str)
{
	char *part = NULL;
	char **result;
	int i = 0;
	int j = 0;
	int k = 0;
	char d[] = " \n";
	char *delim;

	delim = d;

	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
		k++;
	}
	i++;

	str -= k;

	result = malloc(sizeof(char *) * (++i));
	if (result == NULL)
		return (NULL);

	part = strtok(str, delim);
	while (part)
	{
		result[j++] = strdup(part);
		part = strtok(NULL, delim);
	}
	result[j] = NULL;

	return (result);
}