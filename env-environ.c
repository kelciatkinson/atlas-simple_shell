#include "shell.h"


char *get_env(const char *key_value, char **env)
{
  size_t len = 0;
  int i = 0;

  len = strlen(key_value);

  while (env[i])
  {
	if (strncmp(key_value, env[i], len) == 0)
	{
		if (env[i][len] == '=')
			return (env[i] + len + 1);
	}
	i++;
  }
	return (NULL);
}