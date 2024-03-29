#include "shell.h"

/**
* prompt-      print a prompt if running in interactive mode.
*              also, get a line and put it into the buffer.
*
* @buffer:     the buffer to put the line into from getline
* @buffersize: how big the buffer is
*
* Return:      the number of bytes read from getline
*/

ssize_t prompt(char **buffer, size_t *buffersize)
{
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	return (getline(buffer, buffersize, stdin));
}
