#include "shell.h"

/**
 * free_double_pointer- free the memory for a double char pointer
 *
 * @a:                  the double pointer to free
 *
 * Return:              0 or 1
 */

int free_double_pointer(char **a)
{
	int i = 0;

	if (!a)
		return (0);

	while (a[i])
	{
		free(a[i]);
		a[i] = NULL;
		i++;
	}
	
	return (1);
}
