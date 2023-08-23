#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

/* Function prototypes */
void display_prompt(void);
char *read_command(void);
int execute_command(char *command);
void shell_main(void);
void prompt_main(void);

#endif /* MAIN_H */

