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
	char *cmd = NULL;

	if (argv)
	{
		cmd = which_location(argv[0]);
		if (cmd)
		{
			child_pid = fork();
			if (child_pid == -1)
			{
				perror("Error:");
			}
			if (child_pid == 0)
			{
				if (execve(cmd, argv, environ) == -1)
				{
					perror("Error:");
				}
			}
			else
			{
				wait(&status);
			}
		}
	}
}
