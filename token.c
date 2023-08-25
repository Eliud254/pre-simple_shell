#include "main.h"

char **token(char *str, char *delim)
{
    char *stok, **stoks;
	int count = 0;

	stok = strtok(str, delim);
	stoks = (char **)memory(100, sizeof(char *));

	if (!stoks)
	{
		free(stoks);
		return (NULL);
	}

	while (stok)
	{
		stoks[count] = stok;
		stok = strtok(NULL, delim);
		count++;
	}
	return (stoks);
}