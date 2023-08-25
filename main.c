#include "main.h"

int main(int argc, char **argv)
{
	char *buffer = NULL, *delim = " \n";
	ssize_t line = 0;
	size_t nread = 0;
	int status = 0;
	(void)argc;

	do {
		if (isatty(STDIN_FILENO))
			printf(":) ");
		line = getline(&buffer, &nread, stdin);

		if (line == -1 || _strcmp("exit\n", buffer) == 0)
		{
			free(buffer);
			break;
		}
		buffer[line - 1] = '\0';
		if (_strcmp("env", buffer) == 0)
		{
			_env();
			continue;
		}
		if (_line(buffer) == 1)
		{
			status = 0;
			continue;
		}
		argv = token(buffer, delim);
		argv[0] = _path(argv[0]);

		if (argv[0] != NULL)
			status = execute(argv);
		else
			perror("Error");
		free(argv);
	} while (1);
	return (status);
}