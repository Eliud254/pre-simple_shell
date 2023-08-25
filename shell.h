#ifndef SHELL_H
#define SHELL_H

/* == Global Variables == */
extern char **environ;

/* == Standard Libraries == */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/stat.h>

/* == Struct Varaibles == */

/* == Prototype functions */
char _strlen(char *str);

#endif