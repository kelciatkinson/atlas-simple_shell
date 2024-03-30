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
char *get_env(const char *, char **);
int _wait(void);
int _stat(int, char **);
int main(int, char **, char **);
char **tokenize(char *, char *);
ssize_t prompt(char **, size_t *);
int _isspace(char *);
char *findpath(char *, char **);
int free_double_pointer(char **);
char *_strdup(char *);

#endif
