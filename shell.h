#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_ARGS 64
#define BUILTIN_EXIT 1

void execute_command(char *args[]);
int handle_builtins(char *args[]);
void print_environment(char **env);
char *get_full_path(char *command);



#endif

