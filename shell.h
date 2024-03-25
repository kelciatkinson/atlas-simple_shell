#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

 /** prototypes */
char **get_env(const char *key_value);

#endif