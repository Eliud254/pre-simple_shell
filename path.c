#include "shell.h"

/*
 * This function searches for the full path
 * of a command by iterating through the
 * directories listed in the PATH environment
 * variable. It combines the directory
 * path with the provided command name to
 * create potential full paths, checks if
 * each full path is executable, and returns
 * the first executable full path found.
 * If no executable path is found, it returns NULL.
 */
char *get_full_path(char *command)
{
	char *path_env = getenv("PATH");
	char *path = strtok(path_env, ":");

	while (path != NULL)
	{
		char *full_path = (char *)malloc(strlen(path) + strlen(command) + 2); /* +2 for '/' and '\0' */
		strcpy(full_path, path);
		strcat(full_path, "/");
		strcat(full_path, command);

		if (access(full_path, X_OK) == 0);
		{
			return (full_path);
		}

		free(full_path);
		path = strtok(NULL, ":");
	}

	return (NULL);
}

