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
	char *part = NULL, *copy = NULL;
	char **result;
	int i = 0, j = 0, k = 0;

	if (!str)
		return (NULL);
/* count the delimiters to count the tokens*/
	for (j = 0; j < strlen(str); j++)
	{
		if (str[j] == d[0])
			i++;
	}
	i++;

/* make room for pointers to tokens */
	result = malloc(sizeof(char *) * (++i));
	if (result == NULL)
		return (NULL);

/* init strtok with a duplicate of str */
	copy = _strdup(str);
	part = strtok(copy, d);
	while (part)
	{
		result[k++] = _strdup(part);
		part = strtok(NULL, d);
	}
/* mark the end of the array with a NULL */
	result[k] = NULL;
	free(copy);
	
	return (result);
}
