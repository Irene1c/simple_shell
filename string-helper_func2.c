#include "shell.h"

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
	return (new_str);
}
/**
 * _strcat - concatenates two strings
 * @dest: destination
 * @src: source
 * Return: pointer to resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j;

	while (dest[i] != '\0')
	{
		i++;
	}
	for (j = 0; src[j] != '\0'; ++j, ++i)
	{
		dest[i] = src[j];
	}
	dest[i] = '\0';
	return (dest);
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
