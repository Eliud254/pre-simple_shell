#ifndef _MAIN_H
#define _MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

extern char **environ;

char **token(char *str, char *delim);
char *_path(char *cmd);
int _line(char *buffer);
int _strlen(char *str);
char *_strcat(char *dest, const char *src);
int _strcmp(char *a, char *b);
char* _strcpy(char* dest, const char* src);
char *_getenv(char *_env);
int execute(char **argv);
void memory(unsigned int a, unsigned int b);

#endif