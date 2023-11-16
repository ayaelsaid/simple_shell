#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#define MAXSIZE 1024
#define DELIM " \t\n"
extern char **environ;
int _putchar(char c);
void _prompt(void);
int _exe(char **word, char **environ);
char **_tokenize(char *command);
void _puts(char *str);
char *_strdup(char *str);
ssize_t _read(char **line);
void freestring(char **args);
int _strcmp(char *s1, char *s2);
void _print_env(void);
void _myexit(void);
int main(void);
#endif
