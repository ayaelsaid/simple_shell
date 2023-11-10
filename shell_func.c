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
		i++;
	}
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
		args[i] = NULL;
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
	char **spiltedline;
	int i = 0;

	if (command == NULL)
		return (NULL);
	spiltedline = malloc((MAXSIZE + 1) * sizeof(char *));
	if (spiltedline == NULL)
	{
		free(command);
		return (NULL);
	}
	token = strtok(command, DELIM);
	while (token != NULL)
	{
		spiltedline[i] = _strdup(token);
		if (spiltedline[i] == NULL)
		{
			free(command);
			freestring(spiltedline);
			return (NULL);
		}
		token = strtok(NULL, DELIM);
		i++;
	}
	spiltedline[i] = NULL;
	return (spiltedline);
}
