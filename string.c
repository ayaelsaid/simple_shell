#include "shell.h"
/**
 * _print_env - ...
*/
void _print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
		{
		_puts(environ[i]);
		_putchar('\n');
		}
}
/**
 * _strcmp - ...
 * @s1: ...
 * @s2: ...
 * Return: ...
*/
int _strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (*s1 && *s2)
	{
		if (s1[i] != s2[i])
			return (*s1 - *s2);
	s1++;
	s2++;
	}
	if (*s1 == *s2)
		return (0);
	else if (*s1 < *s2)
		return (-1);
	else
		return (1);
}
