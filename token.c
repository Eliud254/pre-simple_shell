#include "main.h"

// Not Edited.

char **token(char *str, char *delim)
{
    char *token, **tokens;
	int count = 0;

	token = strtok(str, delim);
	tokens = (char **)memory(100, sizeof(char *));

	if (!tokens)
	{
		free(tokens);
		return (NULL);
	}

	while (token)
	{
		tokens[count] = token;
		token = strtok(NULL, delim);
		count++;
	}
	return (tokens);
}