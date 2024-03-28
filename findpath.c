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
 */

char *findpath(char *cmd, char **env)
{
	char **patharray = NULL;
	int i = 0;
	char *str;
	struct stat *buff;

	buff = malloc(sizeof(struct stat));
	if (buff == NULL)
		return (NULL);

	if (stat(cmd, buff) == 0)
		return (cmd);

	patharray = tokenize(get_env("PATH", env), ":");

	str = malloc(strlen(patharray[i]) + 1 + strlen(cmd));
	if (str == NULL)
		return (NULL);

	while (patharray[i])
	{
		sprintf(str, "%s/%s", patharray[i], cmd);
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
