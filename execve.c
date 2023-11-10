#include "shell.h"
/**
 * _exe - ...
 * @word: ...
 * @environ: ...
 * Return: ...
*/
int _exe(char **word, char **environ)
{
	int status = 0;
	pid_t child_pid;

	if (word == NULL || word[0] == NULL)
	{
		return(0);
	}
	child_pid = fork();
	if (child_pid == -1)
	{
		freestring(word);
		exit(100);
	}
	else if (child_pid == 0)
	{
		if (execve(word[0], word, environ) == -1)
		{
			perror(word[0]);
			exit(127);
		}
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
	return (WEXITSTATUS(status));
}
/**
 * *_strdup - a function that returns a pointer to
 *		a newly allocated space in memory
 * @str: string
 * Return: NULL or ptr
*/
char *_strdup(char *str)
{
	unsigned int size;
	char *ptr;
	unsigned int i, j;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i] != '\0')
	i++;
	size = i + 1;
	ptr = (char *) malloc(sizeof(char) * size);
	if (ptr == 0)
		return (NULL);
	for (j = 0; j < size; j++)
	ptr[j] = str[j];
	ptr[size - 1] = '\0';
	return (ptr);
}
