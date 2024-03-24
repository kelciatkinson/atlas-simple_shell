#include <stdio.h>
#include <stdlib.h>

extern char **environ;

char **add_env(const char *key_value)
{
  int i = 0;
  int n = 0;

  while (environ[i])
    i++;

  char **new_env = malloc((i + 2) * sizeof(char *));

  if (new_env == NULL)
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  
}
