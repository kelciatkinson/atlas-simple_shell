#include <stdio.h>
#include <unistd.h>

/**
 * _fork - fork example
 * @new_:  new process to fork
 * Return: Always 0.
 */
int _fork(char *new_)
{
	pid_t my_pid;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return (1);
	}
	my_pid = getpid();
	if (child_pid == 0)
	{
		printf("(%u) Nooooooooo!\n", my_pid);
	}
	else
	{
		printf("(%u) %u, I am your father\n", my_pid, child_pid);
	}
	return (0);
	
}