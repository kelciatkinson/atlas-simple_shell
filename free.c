#include "shell.h"

/**
 * free_double_pointer- 
 *
 * @a:
 *
 * Return: 0 or 1
 */

 int free_double_pointer(char **a)
 {
	int i = 0;

	if (!a)
		return (0);

	while (a[i])
	{
		free (a[i]);
		i++;
	}
	free(a);
	return (1);
 }