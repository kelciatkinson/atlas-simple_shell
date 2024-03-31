#include "shell.h"

void nothing(void);

/**
 * main- main entry point for shell
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
	int fork_result, status = 0;
	char **tokens = NULL;

	argc = argc;
	buffer = malloc(sizeof(char) * buffersize);
	if (buffer == NULL)
		return (-1);

	while (prompt(&buffer, &buffersize) != -1)
	{
		/*printf("buffer is [%s]", buffer);*/
		if (_isspace(buffer) != 1)
		{
			if (strncmp(buffer, "exit", 4) == 0)
			{
				free(buffer);
				buffer = NULL;
				if (status == -1)
					exit(2);
				return (status);
			}
			tokens = tokenize(buffer, " \n");
			found = findpath(tokens[0], env);
			if (found == NULL)
			{
				fprintf(stderr, "%s: 1: %s: not found\n", argv[0], tokens[0]);
				status = EXIT_COMMAND_NOT_FOUND;
			}
			else
			{
				fork_result = fork();
				if (fork_result == -1)
					return (-1);
				if (fork_result == 0)
				{
					if (execve(found, tokens, env) == -1)
					{
						fprintf(stderr, "%s: No such file or directory\n",
						argv[0]);
						exit(EXIT_NO_FILE_OR_DIRECTORY);
					}
					exit (status);
				}
				free(found);
				found = NULL;
				wait(&status);
			}
			free_double_pointer(tokens);
		}
	}
	free(buffer);
	exit(WEXITSTATUS(status));
}
