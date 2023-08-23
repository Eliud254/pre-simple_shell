#include "main.h"

/**
 * shell_main - Shell's main function
 */
void shell_main(void)
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

