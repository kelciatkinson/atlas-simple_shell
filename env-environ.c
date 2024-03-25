#include "shell.h"

char **get_env(const char *key_value)
{
  size_t len = 0;
  int i = 0;
  char **new_env;

  len = strlen(key_value);

  while (env[i])
  {
	if (strncmp(name, env[i], len) == 0)
	{
		if (env[i][len] == '=')
			return (env[i] + len + 1);
		i++;
	}
  }
	return (NULL);
}