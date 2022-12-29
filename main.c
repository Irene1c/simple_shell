#include "shell.h"

/**
 * main - entry point
 * @argc: argument count
 * @argv: arguments
 * Return: nothing
 */
int main(int argc, char **argv)
{
	char *buf = NULL;
	int i = 0;

	(void)argc;

	signal(SIGINT, handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		}
		buf = _readline();
		argv = _tokenize(buf);
		if (argv[0] != NULL)
		{
			if (_strcmp(argv[0], "exit") == 0)
			{
				free(argv);
				free(buf);
				exit(0);
				break;
			}
			else if (_strcmp(argv[0], "env") == 0)
			{
				while (environ[i] != NULL)
				{
					_puts(environ[i]);
					i++;
				}
			}
			else
			{
				_execute(argv);
			}
		}
		free(argv);
		free(buf);
	}
	return (0);
}
