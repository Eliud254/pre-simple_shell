#include "main.h"

char *_path(char *cmd)
{
	char *path = _getenv("PATH");
	char *path_linked = NULL;
	char *path_copy;
	char **path_parsed;
	char *delim = ":";

	struct stat index;
	int path_len = 0;
	int i = 0;

	if (stat(cmd, &index) == 0)
		return (cmd);
	path_copy = malloc(_strlen(path) + 1);
	path_copy = _strcpy(path_copy, path);
	path_parsed = token(path_copy, delim);

	for (; path_parsed[i] ; i++)
	{
		path_len = _strlen(path_parsed[i]);

		if (path_parsed[i][path_len - 1] != '/')
			path_linked = _strcat(path_parsed[i], "/");
		path_linked = _strcat(path_parsed[i], cmd);

		if (stat(path_linked, &index) == 0)
			break;
	}

	free(path_copy);

	if (!path_parsed[i])
	{
		free(path_parsed);
		return (NULL);
	}

	free(path_parsed);
	return (path_linked);
}