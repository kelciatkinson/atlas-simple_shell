#include "shell.h"

/**
 * _isspace- find out if a string is all spaces.
 *
 * @str:    the string to check
 *
 * Return:  1 if all spaces, 0 not all spaces
 *
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
