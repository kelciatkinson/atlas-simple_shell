#include <stdio.h>
#include <stdlib.h>

extern char **env;

char **add_env(const char *key_value)
{
  int count = 0;
  int i = 0;
  char **new_env;

  while (env[count])
    count++;

 new_env = (char **)malloc((count + 2) * sizeof(char *));

  if (new_env == NULL)
  {
    perror("Memory allocation failed");
    exit(EXIT_FAILURE);
  }
  return(new_env);
}
