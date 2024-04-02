#include "shell.h"

/**
 * unset- remove a string from an array of strings based on the beginning of
 *        the string
 *
 * @a:    a pointer to an array of pointers
 * @key:  the string to find
 *
 * Return: 0 success, -1 null pointer provided
 */

int unset(char **a, char *key)
{
	int i;
	size_t len;

	len = strlen(key);

	if (!a)
		return (-1);
	while (a[i])
	{
		if (strncmp(*a[i], *key, len) == 0)
		{
			/* found the key */
		}
	}
}

int main(int argc, char **argv, char **env)
{
 	char *path = {"PATH"};
	unset(env, "PATH");
}
