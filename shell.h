#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

 /** prototypes */
char **get_env(const char *key_value);
int mainmain(void);
int main(int argc, char **argv, char **env);
char **tokenize(char *);

#endif