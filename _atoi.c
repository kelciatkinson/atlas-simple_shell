#include "shell.h"

/**
 * _atoi-  converts a string to an integer
 *
 * @s:     the string to be converted
 *
 * Return: integer found in string
 */

int _atoi(char *s)
{
	int result = 0, op = 1, i = 0;

	while (s[i] != '\0')
	{
		if (s[i] == '-' || s[i] == '+')
			op = (s[i++] == '-') ? -1 : 1;
		else if (s[i] >= '0' && s[i] <= '9')
		{
			result *= 10 + (s[i++] - '0');

			if (!(s[i] >= '0' && s[i] <= '9'))
				break;
		}
		else
			i++;
	}
	return (op * result);
}
