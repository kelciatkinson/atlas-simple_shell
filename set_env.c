#include "shell.h"

/**
 * _setenv-
 *
 * @str:
 * @value:
 * @overwrite: 
 *
 * Return: 0 or 1.
 *
 */

int _setenv(const char *str, const char *value, int overwrite)
{
	int i;

	for (i = 0; value[i]; i++)
	{
		return(value[i]);
	}
	return (0);
}

/**
 * _unsetenv- 
 * 
 * @str:
 * 
 * Return: 0 or 1.
 * 
*/
/* int _unset(const char *str) */
