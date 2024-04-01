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
	int fork_result, status = 0, exit_val = 0;
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
				if (buffer[4] != '\0')
				{
					buffer += 4;
					exit_val = atoi(buffer);
					free(buffer);
					exit(exit_val);
				}
				exit(status);
			}
			if (strncmp(buffer, "env", 3) == 0)
			{
				free(buffer);
				buffer = NULL;
				_printenv(env);
				continue;
			}
			tokens = tokenize(buffer, " \n");
			found = findpath(tokens[0], env);
			if (found == NULL)
			{
				fprintf(stderr, ERR_NOT_FOUND, argv[0], tokens[0]);
				status = EXIT_COMMAND_NOT_FOUND;
			}
			else
			{
				fork_result = fork();
				if (fork_result == -1)
					return (EXIT_FORK_ERROR);
				if (fork_result == 0)
				{
					if (execve(found, tokens, env) == -1)
					{
						fprintf(stderr, ERR_NO_FILE_OR_DIRECTORY, argv[0]);
						exit(EXIT_NO_FILE_OR_DIRECTORY);
					}
					exit (status);
				}
				free(found);
				wait(&status);
				status = WEXITSTATUS(status);
			}
			free_double_pointer(tokens);
		}
	}
	free(buffer);
	exit(status);
}
