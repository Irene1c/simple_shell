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
			_execute(argv);
		}
		free(argv);
		free(buf);
	}
	return (0);
}
