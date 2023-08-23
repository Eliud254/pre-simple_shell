#include "main.h"

/**
 * prompt_main - Prompt's main function
 */
void prompt_main(void)
{
    char *command;

    signal(SIGINT, SIG_IGN);

    do {
        display_prompt();
        command = read_command();

        if (command != NULL) {
            if (execute_command(command) == -1) {
                fprintf(stderr, "Command not found: %s\n", command);
            }
            free(command);
        }
    } while (1);
}

/**
 * display_prompt - Display the shell prompt
 */
void display_prompt(void)
{
    if (isatty(STDIN_FILENO)) {
        write(STDOUT_FILENO, "$ ", 2);
    }
}

/**
 * read_command - Read a command from the user
 *
 * Return: The command entered by the user
 */
char *read_command(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t bytes_read = getline(&line, &bufsize, stdin);

    if (bytes_read == -1) {
        if (feof(stdin)) {
            write(STDOUT_FILENO, "\n", 1);
            exit(0);
        } else {
            perror("read_command");
            exit(1);
        }
    }

    /* Remove the newline character at the end */
    if (line[bytes_read - 1] == '\n') {
        line[bytes_read - 1] = '\0';
    }

    return line;
}

/**
 * execute_command - Execute a command
 * @command: The command to execute
 *
 * Return: 0 on success, -1 on failure
 */
int execute_command(char *command)
{
    pid_t pid;
    int status;

    if (command == NULL || command[0] == '\0') {
        return 0;
    }

    pid = fork();
    if (pid == 0) {
        if (execlp(command, command, (char *)NULL) == -1) {
            return -1;
        }
        exit(0);
    } else if (pid < 0) {
        perror("fork");
    } else {
        wait(&status); /* Use wait instead of waitpid in C90 */
    }

    return 0;
}

