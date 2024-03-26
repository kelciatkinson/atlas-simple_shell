#include "shell.h"

/**
 * Write a UNIX command line interpreter.
 *
 * Usage: simple_shell
 * Your Shell should:
 *
 *  * Display a prompt and wait for the user to type a command. A command line
 *    always ends with a new line.
 *  * The prompt is displayed again each time a command has been executed.
 *  * The command lines are simple, no semicolons, no pipes, no redirections or
 *  * any other advanced features.
 *  * The command lines are made only of one word. No arguments will be passed
 *  * to programs.
 *  * If an executable cannot be found, print an error message and display the
 *  * prompt again.
 *  * Handle errors.
 *  * You have to handle the “end of file” condition (Ctrl+D)
 *
 * You don’t have to:
 *
 *  * use the PATH
 *  * implement built-ins
 *  * handle special characters : ", ', `, \, *, &, #
 *  * be able to move the cursor
 *  * handle commands with arguments
 *  * execve will be the core part of your Shell, don’t forget to pass the
 *    environ to it…
 * 
 * julien@ubuntu:~/shell$ ./shell 
 * #cisfun$ ls
 * ./shell: No such file or directory
 * #cisfun$ /bin/ls
 * barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
 * env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
 * #cisfun$ ^[[D^[[D^[[D
 * ./shell: No such file or directory
 * #cisfun$ ^[[C^[[C^[[C^[[C
 * ./shell: No such file or directory
 * #cisfun$ exit
 * ./shell: No such file or directory
 * #cisfun$ ^C
 * julien@ubuntu:~/shell$ echo "/bin/ls" | ./shell
 * barbie_j       env-main.c  exec.c  fork.c  pid.c  ppid.c    prompt   prompt.c  shell.c  stat.c         wait
 * env-environ.c  exec    fork    mypid   ppid   printenv  promptc  shell     stat test_scripting.sh  wait.c
 * julien@ubuntu:~/shell$
 */

int main(int argc, char **argv, char **env)
{
	char *buffer;
	size_t buffersize = 4096;
	int fork_result;

	buffer = malloc(sizeof(char) * buffersize);
	if (buffer == NULL)
		return (-1);

	while (1)
	{
		printf("#cisfun$ ");
		getline(&buffer, &buffersize, stdin);
		if (strncmp(buffer, "exit", 4) == 0)
			break;
		fork_result = fork();
		if (fork_result == -1)
			return (-1);
		if (fork_result == 0)
		{
			tokenize(buffer);
			printf("child process\n");
			return (0);
		}
		wait(NULL);
		printf("return to main.\n");
	}

	free(buffer);
	return (0);
}

char **tokenize(char *str)
{
	char *part;
	int i;

	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	i++;
	/* i contains the number of words. TODO: malloc the array*/
}