#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ()
{
	char *buffer;
	size_t buffsize = 4095;

	buffer = (char *)malloc(sizeof(char) * buffsize);
	if (buffer == NULL)
		return (-1);

	while (1)
	{
		printf("$ ");
		getline(&buffer, &buffsize, stdin);
		if (strncmp(buffer, "exit", 4) == 0)
			break;
		printf("%s", buffer);
	}
	free(buffer);
	return (0);
}
