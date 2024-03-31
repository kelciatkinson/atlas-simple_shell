#include "shell.h"

extern char **environ;

/**
 * _printenv- 
 * 
 * @env:
 * 
 * Return:
 *
 */

int _printenv(char **env)
{
	int i = 0;
	
	while (*env)
	{
		printf("%s\n", environ[i]);
		i++;
	}
	return (0);
}
