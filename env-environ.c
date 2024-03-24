#include <stdio.h>
#include <stdlib.h>

extern char **env;

char **add_env(const char *key_value)
{
  int i = 0;
  int n = 0;
  char **new_env;

  while (env[i])
    i++;

 new_env = (char **)malloc((i + 2) * sizeof(char *));

  if (new_env == NULL)
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  return(new_env);
}
