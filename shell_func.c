#include "shell.h"
/**
 * _putchar - ...
 * @c: ...
 * Return: ...
*/
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _puts - ...
 * @str: ...
 * Return: ...
*/
void _puts(char *str)
{
	int i = 0;

	while (str && str[i] != '\0')
	{
		_putchar(str[i]);
	}
	_putchar('\n');
}
/**
 * _prompt - ...
 * Return: ...
*/
void _prompt(void)
{
	_puts("#cisfun$ ");
	fflush(stdout);
}
/**
 * freestring - ...
 * @args: ...
 * Return: ...
*/
void freestring(char **args)
{
	int i;

	if (args == NULL)
	return;
	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);
}
/**
 * _tokenize - spilt command
 * @command: ...
 * Return: ...
*/
char **_tokenize(char *command)
{
	char *token;
	char **argv;
	size_t argc = 1;

	if (command == NULL)
		return (NULL);
	argv = malloc((MAXSIZE + 1) * sizeof(char *));
	if (argv == NULL)
	{
		free(command);
		return (NULL);
	}
	token = strtok(command, DELIM);
	while (token != NULL && argc < MAXSIZE)
	{
		argv[argc] = _strdup(token);
		if (argv[argc] == NULL)
		{
			free(command);
			freestring(argv);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		argc++;
	}
	argv[argc] = NULL;
	return (argv);
}
