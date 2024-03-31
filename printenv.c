#include "shell.h"

/**
 * _printenv- prints the current environment when called
 * 
 * @env:      the environment
 * 
 * Return:    always 0
 *
 */

void _printenv(char **env)
{
	int i = 0;
	
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
}
