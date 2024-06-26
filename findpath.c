#include "shell.h"

/**
 * findpath- figure out if a command can be executed where it's at or figure
 *           out if it is in the path somewhere
 *
 * @cmd:     the command to look for
 * @env:     an environment to get the path from
 *
 * Return:   char pointer to the executable including any path info or NULL if
 *           it wasn't found anywhere
 *
 */

char *findpath(char *cmd, char **env)
{
	char **patharray = NULL;
	int i = 0;
	char *path_and_command;
	struct stat *buff;

	buff = malloc(sizeof(struct stat));
	if (buff == NULL)
		return (NULL);

	if ((stat(cmd, buff) == 0) && (strchr(cmd, '/')))
	{
		free(buff);
		return (_strdup(cmd));
	}

	patharray = tokenize(get_env("PATH", env), ":");

	if (patharray == NULL)
	{
			free(buff);
			return (NULL);
	}

	while (patharray[i])
	{
		path_and_command = malloc(strlen(patharray[i]) + 2 + strlen(cmd));
		if (path_and_command == NULL)
		{
			free(buff);
			return (NULL);
		}

		sprintf(path_and_command, "%s/%s", patharray[i], cmd);
		if (stat(path_and_command, buff) == 0)
		{
			free(buff);
			free_double_pointer(patharray);
			return (path_and_command);
		}
		i++;
		free(path_and_command);
	}
	free(buff);
	free_double_pointer(patharray);
	
	return (NULL);
}
