#include "shell.h"

/**
 * _tokenize - creates tokens
 * @line: line to create tokens from
 * Return: pointer to the tokens
 */
char **_tokenize(char *line)
{
	char **args;
	int size = 1024;
	char *token;
	int i = 0;
	char *delimiter = " \t\r\n";

	args = malloc(size * sizeof(char *));
	if (args == NULL)
	{
		exit(1);
	}
	token = strtok(line, delimiter);
	while (token != NULL)
	{
		args[i] = token;
		i++;
		if (i >= size)
		{
			size = (int) (size * 2);
			args = _realloc(args, size, size * sizeof(char *));
		}
		token = strtok(NULL, delimiter);
	}
	args[i] = NULL;
	return (args);
}
