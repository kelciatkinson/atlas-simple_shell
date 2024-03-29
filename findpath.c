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
	printf("malloc findpath buff for struct stat\n");
	if (buff == NULL)
		return (NULL);

	if (stat(cmd, buff) == 0)
	{
		free(buff);
		printf("free findpath buff for struct stat\n");
		return (cmd);
	}

	patharray = tokenize(get_env("PATH", env), ":");

	while (patharray[i])
	{
		str = malloc(strlen(patharray[i]) + 1 + strlen(cmd));
		printf("malloc findpath str for patharray[%d]", i);
		printf("at %s plus one plus strlen(cmd)", patharray[i]);
		printf("is %lu\n", strlen(cmd));
		if (str == NULL)
		{
			free(buff);
			printf("free findpath buff for struct stat\n");
			return (NULL);
		}
		sprintf(str, "%s/%s", patharray[i], cmd);
		if (stat(str, buff) == 0)
		{
			free(buff);
			printf("free findpath buff for struct stat\n");
			free_double_pointer(patharray);
			return (str);
		}
		i++;
		free(str);
		printf("free findpath str end of loop\n");
	}
	free(buff);
	printf("free findpath buff for struct stat\n");
	free_double_pointer(patharray);
	free(str);
	printf("free findpath str\n");
	return (NULL);
}
