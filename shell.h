#ifndef _SHELL_H_
#define _SHELL_H_

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
int _printenv(char **env);

/**
 * MACROS
 */
#define EXIT_FORK_ERROR -1
#define EXIT_SUCCESS 0
#define EXIT_GENERAL_ERROR 1
#define EXIT_NO_FILE_OR_DIRECTORY 2
#define EXIT_MISUSE_OF_SHELL_BUILTINS 2
#define EXIT_COMMAND_INVOKED_CANNOT_EXECUTE 126
#define EXIT_COMMAND_NOT_FOUND 127

#define ERR_NO_FILE_OR_DIRECTORY "%s: No such file or directory\n"
#define ERR_NOT_FOUND "%s: 1: %s: not found\n"

#endif
