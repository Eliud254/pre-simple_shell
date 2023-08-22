#include "shell.h"

/**
 * print_environment - Print the environment variables.
 * @env: Array of strings containing environment variables.
 */
void print_environment(char **env)
{
	int i;

	for (i = 0; env[i] != NULL; i++)
	{
		printf("%s\n", env[i]);
	}
}

