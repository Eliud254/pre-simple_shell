#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* Function prototypes */
void prompt(void);
char *read_line(void);
char **split_line(char *line);
int execute(char **args);
void free_args(char **args);
int exit_builtin(char **args);
int env_builtin(char **args);

#endif /* MAIN_H */

