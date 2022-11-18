#include "shell.h"

/**
 * handler - handles signals
 * @sig: integer associated with the signal
 * Return: nothing
 */
void handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^C^C ", 6);
}
