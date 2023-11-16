#include "shell.h"
/**
 * _read - ...
 * @line: ...
 * Return: ...
*/
ssize_t _read(char **line)
{
	ssize_t read_lin = 0;
	size_t n = 0;

	*line = NULL;
	if (isatty(STDIN_FILENO))
		_prompt();

	read_lin = getline(line, &n, stdin);
	if (read_lin == -1)
	{
		free(*line);
		*line = NULL;
		return (0);
	}
	return (read_lin);
}
/**
 * _myexit - ...
*/
void _myexit(void)
{
	exit(0);
}
/**
 * main - ...
 * Return: ...
*/
int main(void)
{
	ssize_t readline;
	char *line;
	char **mytokens;

	while (1)
	{
	readline = _read(&line);
	if (readline == 0)
	{
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
		}
	return (0);
	}
	mytokens = _tokenize(line);
	if (mytokens == NULL)
	{
	perror("Error");
	return (0);
	}
	if (_strcmp(mytokens[0], "exit") == 0)
	{
		freestring(mytokens);
		free(line);
		line = NULL;
		_myexit();
	}
	else if (_strcmp(mytokens[0], "env") == 0)
		_print_env();
	else
	 _exe(mytokens, environ);
	freestring(mytokens);
	mytokens = NULL;
	free(line);
	line = NULL;
	}
	return (0);
}
