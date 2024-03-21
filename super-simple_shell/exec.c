#include <stdio.h>
#include <unistd.h>

/**
 * _execve -  Execute a process
 *
 * @execfile: The full path and filename to execute.
 *
 * Return:    0 success, -1 error
 */

int _execve(char *execfile)
{
	char *argv[] = {*execfile, NULL};

	if (execve(*execfile, *execfile, NULL) == -1)
	{
		perror("Error:");
		return (-1);
	}

	return (0);
}