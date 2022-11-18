#include "shell.h"

/**
 * _realloc - reallocate memory
 * @ptr: old memory block
 * @old_s: old strng size
 * @new_s: new string size
 * Return: new memory block
 */
void *_realloc(void *ptr, unsigned int old_s, unsigned int new_s)
{
	char *new;
	char *temp;
	unsigned int i;

	if (old_s == new_s)
	{
		return (ptr);
	}
	if (ptr == NULL)
	{
		new = malloc(new_s);
		return (new);
	}
	if (new_s == 0 && ptr != NULL)
	{
		free(ptr);
		return (NULL);
	}
	new = malloc(new_s);
	temp = ptr;
	if (new == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < old_s; i++)
	{
		new[i] = temp[i];
	}
	free(ptr);
	free(temp);
	free(new);
	return (new);
}
