#include "shell.h"

/**
 * handle_builtins - Check if a command is a built-in
 *                   and return the corresponding value.
 * @args: Array of strings containing command and arguments.
 *
 * Return: BUILTIN_EXIT if the command is "exit", 0 otherwise.
 */
int handle_builtins(char *args[])
{
	if (strcmp(args[0], "exit") == 0)
	{
		return (BUILTIN_EXIT);
	}
	return (0);
}

