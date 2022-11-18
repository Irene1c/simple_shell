#include "shell.h"

/**
 * _execute - execute commands
 * @argv: command to be executed
 * Return: nothing
 */
void _execute(char **argv)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
	}
	if (child_pid == 0)
	{
		if (execve(argv[0], argv, environ) == -1)
		{
			perror("Error:");
		}
	}
	else
	{
		wait(&status);
	}
}
