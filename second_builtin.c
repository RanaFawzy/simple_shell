#include "shell.h"

/**
 * _myhistory - displays the history list, one command by line, preceded
 *              with line numbers, starting at 0.
 * @info: Struct of potential arguments to maintain function prototype
 *  Return: 0 (true)
 */

int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}


/**
 * print_alias - function to print  alias str
 * @node: alias node
 * Return:  0 ( success)
 *          1 (failure)
 */


int print_alias(list_t *node)
{
char *p = NULL, *a = NULL;

if (node)
{
	p = _strchr(node->str, '=');
	for (a = node->str; a <= p; a++)
	_putchar(*a);
	_putchar('\'');
	_puts(p + 1);
	_puts("'\n");
	return (0);
}
return (1);
}

/**
 * unset_alias - function that set alias to string
 * @info: the parameter structure
 * @str: alias str
 * Return: 0 (on true)
 *         1 (on failure)
 */
int unset_alias(info_t *info, char *str)
{
	char *p, c;
	int ret;

	p = _strchr(str, '=');
	if (!p)
		return (1);
	c = *p;
	*p = 0;
	ret = delete_node_at_index(&(info->alias),
		get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*p = c;
	return (ret);
}
