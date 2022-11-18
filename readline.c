#include "shell.h"

/**
 * _readline - reads the line from user
 * Return: the line
 */
char *_readline(void)
{
	char *line = NULL;
	size_t len = 0;
	int i = 0;
	ssize_t size;

	size = getline(&line, &len, stdin);
	if (size == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "\n", 1);
		}
		free(line);
		exit(0);
	}
	i = _strlen(line);
	line[i - 1] = '\0';

	return (line);
}
