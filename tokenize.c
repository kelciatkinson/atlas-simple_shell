#include "shell.h"

/**
* tokenize- make a string into tokens
*
* @str:     the string to tokenize
* @d:       deliminator
*
* Return:   an array of pointes to strings
*
*/

char **tokenize(char *str, char *d)
{
	char *part = NULL;
	char **result;
	int i, j, k;
	
	i = j = k = 0;

	while (*str)
	{
		if (*str == d[0])
			i++;
		str++;
		k++;
	}
	i++;

	str -= k;

	result = malloc(sizeof(char *) * (++i));
	if (result == NULL)
		return (NULL);

	part = strtok(strdup(str), d);
	while (part)
	{
		result[j++] = strdup(part);
		part = strtok(NULL, d);
	}
	result[j] = NULL;

	return (result);
}
