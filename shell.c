#include "shell.h"

int main(void)
{
    char *buffer = NULL;
    size_t bufsize = 0;
    ssize_t characters;
    char *args[MAX_ARGS] = {NULL};

    while (1)
    {
        char *token;
        int i = 1;

        printf("($) ");
        characters = getline(&buffer, &bufsize, stdin);
        if (characters == -1)
        {
            putchar('\n');
            free(buffer);
            exit(EXIT_SUCCESS);
        }
        buffer[characters - 1] = '\0';

        token = strtok(buffer, " ");
        args[0] = token;

        while (token != NULL)
        {
            token = strtok(NULL, " ");
            args[i] = token;
            i++;
        }

        if (handle_builtins(args) == BUILTIN_EXIT)
        {
            free(buffer);
            exit(EXIT_SUCCESS);
        }

        execute_command(args);
    }
    return (0);
}

