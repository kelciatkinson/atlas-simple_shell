#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

 /** prototypes */
char *get_env(const char *key_value, char **env);
int mainmain(void);
int main(int argc, char **argv, char **env);
char **tokenize(char *, char *);
ssize_t prompt(char *, size_t *);
int _isspace(char *str);
char *findpath(char *cmd, char **env);

#endif