#include "shell.h"

/**
 * _setenv - function to define  new variable or upgrades an existing one
 * @info: Struct of potential arguments maintain a prototype
 * @var: the string env var property
 * @value: string enviroment var value
 *  Return: 0 (success)
 */

int _setenv(info_t *info, char *var, char *value)
{
	char *buf = NULL;
	list_t *node;
	char *p;

	if (!var || !value)
		return (0);

	buf = malloc(_strlen(var) + _strlen(value) + 2);
	if (!buf)
		return (1);
	_strcpy(buf, var);
	_strncat(buf, "=");
	_strncat(buf, value);
	node = info->env;
	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			free(node->str);
			node->str = buf;
			info->env_changed = 1;
			return (0);
		}
		node = node->next;
	}
	add_node_end(&(info->env), buf, 0);
	free(buf);
	info->env_changed = 1;
	return (0);
}



/**
 * _unsetenv - function delete the environment variable
 * @info: Struct of potential arguments to maintain prototype.
 *  Return: 1 (success)
 *               0 else
 * @var: string env var property
 */


int _unsetenv(info_t *info, char *var)
{
	list_t *node = info->env;
	size_t i = 0;
	char *p;

	if (!node || !var)
		return (0);

	while (node)
	{
		p = starts_with(node->str, var);
		if (p && *p == '=')
		{
			info->env_changed = delete_node_at_index(&(info->env), i);
			i = 0;
			node = info->env;
			continue;
		}
		node = node->next;
		i++;
	}
	return (info->env_changed);
}

/**
 * get_environ - function that return str array copy of our environ
 * @info: Structure of potential argument maintain function prototype.
 * Return:  0 (true)
 */

char **get_environ(info_t *info)
{
if (!info->environ || info->env_changed)
{
	info->environ = list_to_strings(info->env);
	info->env_changed = 0;
}

return (info->environ);
}
