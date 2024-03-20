/**
 * Write a program that prints all the arguments, without using ac.
 */

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	while (*argv)
	{
		printf("%s\n",  *argv);
		argv++;
	}
	return (0);
}
