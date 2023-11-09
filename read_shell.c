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

	while (1)
	{
	if (isatty(STDIN_FILENO))
	_prompt();
	read = getline(line, &n, stdin);
	if (read == -1)
	{
		free(*line);
		return (0);
	}
	(*line)[read - 1] = '\0';
	}
	return (read);
}
/**
 * main - ...
 * @argv: ...
 * @argc: ...
 * Return: ...
*/
int main(int argc, char **argv)
{
	ssize_t readline;
	(void)argc;

	while (1)
	{
	char *line = NULL;

	readline = _read(&line);
	if (readline == 0)
	{
		if (isatty(STDIN_FILENO))
		{
			_putchar('\n');
		}
		free(line);
		exit(0);
	}
	argv = _tokenize(line);
	if (argv == NULL)
	{
	free(line);
	}
	_exe(argv, argv, environ);
	}
	return (0);
}
