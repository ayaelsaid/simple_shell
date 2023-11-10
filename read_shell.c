#include "shell.h"
/**
 * _read - ...
 * @line: ...
 * Return: ...
*/
ssize_t _read(char **line)
{
	ssize_t read;
	size_t n = 0;

	if (isatty(STDIN_FILENO))
	_prompt();
	read = getline(line, &n, stdin);
	if (read == -1)
	{
		free(*line);
		return (0);
	}
	return (read);
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
	return (0);
	}
	 _exe(mytokens, environ);
	freestring(mytokens);
	mytokens = NULL;
	free(line);
	line = NULL;
	}
	return (0);
}
