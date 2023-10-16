#include "shell.h"


/**
 * _mysetenv - function to Initial  new variable,upgrade existing one
 * @info: Struct of potential arguments maintain prototype.
 * Return: 0 (success)
 */
int _mysetenv(info_t *info)
{
	if (info->argc != 3)
	{
		_eputs("Incorrect number of arguements\n");
		return (1);
	}
	if (_setenv(info, info->argv[1], info->argv[2]))
		return (0);
	return (1);
}


/**
 * populate_env_list - function that populate env linked list
 * @info: Struct of potential arguments maintain prototype
 * Return: 0 (success)
 */
int populate_env_list(info_t *info)
{
list_t *node = NULL;
size_t i;

for (i = 0; environ[i]; i++)
	add_node_end(&node, environ[i], 0);
info->env = node;
return (0);
}


/**
 * _eputs - functio print string
 * @str: input string
 * Return: void
 */

void _eputs(char *str)
{
	int i = 0;

	if (!str)
		return;
	while (str[i] != '\0')
	{
		_eputchar(str[i]);
		i++;
	}
}

/**
 * _eputchar - function puts character c to stderr
 * @c: input character
 * Return:  1 (true)
 *          -1 (error)
 */


int _eputchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];

if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
	write(2, buf, i);
	i = 0;
}
if (c != BUF_FLUSH)
	buf[i++] = c;
return (1);
}

/**
 * _putfd - function puts character c to given fd
 * @c: input char
 * @fd: file descriptors
 * Return: 1 (true)
 *         -1 (false)
 */

int _putfd(char c, int fd)
{
	static int i;
	static char buf[WRITE_BUF_SIZE];

	if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
	{
		write(fd, buf, i);
		i = 0;
	}
	if (c != BUF_FLUSH)
		buf[i++] = c;
	return (1);
}
