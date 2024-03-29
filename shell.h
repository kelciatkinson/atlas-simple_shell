#ifndef SHELL
#define SHELL

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>

/** 
 * prototypes
 */
char *get_env(const char *key_value, char **env);
int wait(void);
int stat(int ac, char **av);
int main(int argc, char **argv, char **env);
char **tokenize(char *, char *);
ssize_t prompt(char **, size_t *);
int _isspace(char *str);
char *findpath(char *cmd, char **env);
int free_double_pointer(char **a);

#endif
