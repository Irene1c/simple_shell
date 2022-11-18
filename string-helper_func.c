#include "shell.h"

/**
 * _strlen - length of string
 * @s: the string
 * Return: the length
 */
int _strlen(char *s)
{
	int i = 0;

	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}
/**
 * _strdup - duplicate string
 * @str: the string
 * Return: pointer to the dupicated string
 */
char *_strdup(char *str)
{
	char *new_str;

	if (str == NULL)
	{
		return (NULL);
	}
	new_str = malloc(_strlen(str) + 1);
	if (new_str == NULL)
	{
		return (NULL);
	}
	_strcpy(new_str, str);
	free(new_str);
	return (new_str);
}
/**
 * _strcpy - copies a string
 * @dest: destination
 * @src: source
 * Return: cpoied string
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
