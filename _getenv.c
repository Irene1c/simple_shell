#include "shell.h"

/**
*_getenv - get environmental variable
*@name: the variable
*Return: pointer to corresponding value string
*/
char *_getenv(const char *name)
{
	int i;
	char *value;

	for (i = 0; environ[i]; i++)
	{
		if (match_variable(environ[i], name))
		{
			value = environ[i];
			return (get_val(value));
		}
	}
	return (NULL);
}
/**
 * match_variable - compare variable name
 * @varname: name of variable
 * @pname: name of variable required
 * Return: 0 or 1
 */
int match_variable(const char *varname, const char *pname)
{
	int i;

	for (i = 0; varname[i] != '='; i++)
	{
		if (varname[i] != pname[i])
		{
			return (0);
		}
	}
	return (1);
}
/**
 * get_val - get corresponding value string
 * @s: the string
 * Return: the string or NULL
 */
char *get_val(char *s)
{
	int i = 0;

	while (s[i])
	{
		if (s[i] == '=')
			return (s + 1);
		s++;
	}
	return (NULL);
}
