#include "main.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0
 */
int main(void)
{
    char *line;
    char **args;
    int status;

    signal(SIGINT, SIG_IGN);

    do {
        prompt();
        line = read_line();
        args = split_line(line);
        status = execute(args);

        free(line);
        free_args(args);
    } while (status);

    return EXIT_SUCCESS;
}

/**
 * prompt - Display the shell prompt
 */
void prompt(void)
{
    if (isatty(STDIN_FILENO))
        write(STDOUT_FILENO, "$ ", 2);
}

/**
 * read_line - Read a line of input from the user
 *
 * Return: The input line
 */
char *read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t bytes_read = getline(&line, &bufsize, stdin);

    if (bytes_read == -1) {
        if (feof(stdin)) {
            write(STDOUT_FILENO, "\n", 1);
            exit(EXIT_SUCCESS);
        } else {
            perror("read_line");
            exit(EXIT_FAILURE);
        }
    }

    return line;
}

/**
 * split_line - Split a line into individual tokens
 * @line: The input line
 *
 * Return: An array of tokens
 */
char **split_line(char *line)
{
    const char *delimiter = " \t\r\n\a";
    char *token;
    size_t bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char *));

    if (!tokens) {
        perror("split_line");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, delimiter);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char *));
            if (!tokens) {
                perror("split_line");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, delimiter);
    }
    tokens[position] = NULL;

    return tokens;
}

/**
 * execute - Execute a command
 * @args: An array of command arguments
 *
 * Return: Always 1
 */
int execute(char **args)
{
    pid_t pid;
    int status;

    if (args[0] == NULL)
        return 1;

    if (strcmp(args[0], "exit") == 0) {
        return exit_builtin(args);
    } else if (strcmp(args[0], "env") == 0) {
        return env_builtin(args);
    }

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("execute");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("fork");
    } else {
        waitpid(pid, &status, WUNTRACED);
    }

    return 1;
}

/**
 * free_args - Free the memory allocated for argument array
 * @args: An array of arguments
 */
void free_args(char **args)
{
    size_t i;
    for (i = 0; args[i] != NULL; i++) {
        free(args[i]);
    }
    free(args);
}


/**
 * exit_builtin - Exit the shell
 * @args: An array of arguments
 *
 * Return: Always 0 (to terminate the shell)
 */
int exit_builtin(char **args)
{
    (void) args; /* Unused parameter */
    return 0;
}

/**
 * env_builtin - Print the environment
 * @args: An array of arguments
 *
 * Return: Always 1 (to continue shell execution)
 */
int env_builtin(char **args)
{
    extern char **environ;
    char **env = environ;

    (void) args; /* Unused parameter */

    while (*env) {
        printf("%s\n", *env);
        env++;
    }

    return 1;
}

