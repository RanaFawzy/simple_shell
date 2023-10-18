#include "shell.h"

/**
 * _isalpha - function for alphabetic char
 * @c: input to check
 * Return: 1 (true)
 *              0 (else)
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}


/**
 * is_delim - function check for delimeter
 * @c: character input
 * @delim: string delmi
 * Return: 1 (success)
 */


int is_delim(char c, char *delim)
{
while (*delim)
	if (*delim++ == c)
		return (1);
return (0);
}




/**
 * _atoi - function to make string  an integer
 * @s: input string
 * Return: integer
 *          0 (success)
 */


int _atoi(char *s)
{
	int i, sign = 1, flag = 0, output;
	unsigned int result = 0;

	for (i = 0; s[i] != '\0' && flag != 2; i++)
	{
		if (s[i] == '-')
			sign *= -1;
		if (s[i] >= '0' && s[i] <= '9')
		{
			flag = 1;
			result *= 10;
			result += (s[i] - '0');
			}
		else if (flag == 1)
			flag = 2;
	}

	if (sign == -1)
		output = -result;
	else
		output = result;

	return (output);
}



/**
 * _myhelp -  function change the current directory
 * @info: Struct of containing potential arguments
 * constant func prototypes
 * Return: 0 (success)
 */


int _myhelp(info_t *info)
{
char **arg_array;

arg_array = info->argv;
_eputs("help call works. Function not yet implemented \n");
if (0)
	_eputs(*arg_array); /* temp att_unused workaround */
return (0);
}
