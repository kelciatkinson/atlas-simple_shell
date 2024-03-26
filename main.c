#inlcude "shell.h"

/**
 * main- here is a description
 *
 * @parameter: here is a parameter
 *
 * Return: here is a return value
 */

 int _main(void)
 {
	char *buffer;
	size_t buffsize = 4095;

	/* allocating memory */
	buffer = (char *)malloc(sizeof(char) * buffsize);
	if (buffer == NULL)
		return (-1);

	/* continuous loop to get input from user */
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