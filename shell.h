#ifndef SIMPLE_SHELL
#define SIMPLE_SHELL

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sys/stat.h>

extern char **environ;

char *_readline(void);
char **_tokenize(char *line);
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s);
int _strlen(char *s);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);
void handler(int sig);
void _execute(char **argv);

#endif
