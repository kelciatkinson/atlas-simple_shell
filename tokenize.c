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
	printf("malloc result array for %d x 8 bytes\n", i);
	if (result == NULL)
		return (NULL);

	copy = strdup(str);
	printf("malloc copy via strdup for [%s]\n\n", str);
	part = strtok(copy, d);

	while (part)
	{
		result[j++] = strdup(part);
		printf("malloc result[%d] via strdup for [%s]\n\n", j - 1, result[j - 1]);
		part = strtok(NULL, d);
	}
	result[j] = NULL;

	free(copy);
	printf("free copy\n");
	return (result);
}
