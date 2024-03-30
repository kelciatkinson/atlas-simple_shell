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
	char *copy = NULL;
	char **result;
	int i = 0, j = 0;

	if ((!str) && (strcmp(str, "") != 0))
		return (NULL);

	copy = _strdup(str);
	while (*copy)
	{
		if (*copy == d[0])
			i++;
		copy++;
	}
	i++;
	free(copy);
	copy = _strdup(str);

	result = malloc(sizeof(char *) * (++i));
	if (result == NULL)
		return (NULL);

	part = strtok(copy, d);

	while (part)
	{
		result[j++] = _strdup(part);
		part = strtok(NULL, d);
	}
	result[j] = NULL;

	free(copy);
	return (result);
}
