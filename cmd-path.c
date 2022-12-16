#include "shell.h"

/**
 * which_location - get command location
 * @cmd: the command
 * Return: command path
 */
char *which_location(char *cmd)
{
	char *path, *path_cpy;
	char *token, *cmd_path;
	int i, d;
	struct stat st;

	path = _getenv("PATH");
	if (path)
	{
		path_cpy = _strdup(path);
		token = strtok(path_cpy, ":");
		while (token != NULL)
		{
			d = _strlen(token);
			i = _strlen(cmd);
			cmd_path = malloc(i + d + 2);
			_strcpy(cmd_path, token);
			_strcat(cmd_path, "/");
			_strcat(cmd_path, cmd);
			_strcat(cmd_path, "\0");

			if (stat(cmd_path, &st) == 0)
			{
				free(path_cpy);
				return (cmd_path);
			}
			else
			{
				free(cmd_path);
				token = strtok(NULL, ":");
			}
		}
		free(path_cpy);
		if (stat(cmd, &st) == 0)
		{
			return (cmd);
		}
	}
	return (NULL);
}
