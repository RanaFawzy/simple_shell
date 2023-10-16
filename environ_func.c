#include "shell.h"


/**
 * _putsfd - function print string input
 * @str: input string
 * @fd:  filed scriptor
 * Return: integer
 */

int _putsfd(char *str, int fd)
{
	int i = 0;

	if (!str)
		return (0);
	while (*str)
	{
		i += _putfd(*str++, fd);
	}
	return (i);
}


/**
 * _myunsetenv - function delete an environ variables
 * @info: Struct of potential arguments which  maintain prototype
 * Return: 0 (success)
 */

int _myunsetenv(info_t *info)
{
int i;

if (info->argc == 1)
{
	_eputs("Too few arguements.\n");
	return (1);
}
for (i = 1; i <= info->argc; i++)
	_unsetenv(info, info->argv[i]);

return (0);
}


/**
 * _myenv - function used to print the  environment
 * @info: Struct of potential arguments which  maintain prototype
 * Return: 0 (success)
 */
int _myenv(info_t *info)
{
print_list_str(info->env);
return (0);
}


/**
 * _getenv - func to get value of an environment variables
 * @info: Structure containing potential arguments. Used to maintain
 * @name: the variable name
 * Return: environment value
 */


char *_getenv(info_t *info, const char *name)
{
	list_t *node = info->env;
	char *p;

	while (node)
	{
		p = starts_with(node->str, name);
		if (p && *p)
			return (p);
		node = node->next;
	}
	return (NULL);
}
