#include "shell.h"

/**
 * print_error - function writes an error message
 * @info:  parameter and return info struct
 * @estr: string containing specifed error type
 * Return: 0 (number wasn’t string)
 *         (converted number)
 *        -1 (false)
 */
void print_error(info_t *info, char *estr)
{
	_eputs(info->fname);
	_eputs(": ");
	print_d(info->line_count, STDERR_FILENO);
	_eputs(": ");
	_eputs(info->argv[0]);
	_eputs(": ");
	_eputs(estr);
}

/**
 * _erratoi - function convert a str to  int
 * @s:  str to be converted
 * Return: 0 (number wasn’t string
 *         converted number
 *       -1 (failure)
 */

int _erratoi(char *s)
{
int i = 0;
unsigned long int result = 0;

if (*s == '+')
s++; /* TODO: why does this make main return 255? */
for (i = 0;  s[i] != '\0'; i++)
{
	if (s[i] >= '0' && s[i] <= '9')
	{
		result *= 10;
		result += (s[i] - '0');
		if (result > INT_MAX)
			return (-1);
	}
	else
		return (-1);
}
return (result);
}




/**
 * convert_number - function converts  a number
 * @num: the input number
 * @base: base.
 * @flags: argu flags
 * Return: str
 */
char *convert_number(long int num, int base, int flags)
{
	static char *array;
	static char buffer[50];
	char sign = 0;
	char *ptr;
	unsigned long n = num;

	if (!(flags & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	array = flags & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	ptr = &buffer[49];
	*ptr = '\0';

	do	{
		*--ptr = array[n % base];
		n /= base;
	} while (n != 0);

	if (sign)
		*--ptr = sign;
	return (ptr);
}


/**
 * print_d -  function to print decimal int number (base 10)
 * @input:  input number
 * @fd:  file descriptor write into it
 * Return: decimal number
 */
int print_d(int input, int fd)
{
int (*__putchar)(char) = _putchar;
int i, count = 0;
unsigned int _abs_, current;

if (fd == STDERR_FILENO)
	__putchar = _eputchar;
if (input < 0)
{
	_abs_ = -input;
	__putchar('-');
	count++;
}
else
	_abs_ = input;
current = _abs_;
for (i = 1000000000; i > 1; i /= 10)
{
	if (_abs_ / i)
	{
		__putchar('0' + current / i);
		count++;
	}
	current %= i;
}
__putchar('0' + current);
count++;

return (count);
}
