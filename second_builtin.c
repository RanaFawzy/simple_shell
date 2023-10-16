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

