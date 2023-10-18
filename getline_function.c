#include "shell.h"



/**
 * get_input - function get a line minus the newline
 * @info: a parameter structure
 * Return: number of bytes
 */
ssize_t get_input(info_t *info)
{
	static char *buf; /*  ';' command chain buffer */
	static size_t i, j, len;
	ssize_t r = 0;
	char **buf_p = &(info->arg), *p;

	_putchar(BUF_FLUSH);
	r = input_buf(info, &buf, &len);
	if (r == -1) /* EOF */
		return (-1);
	if (len) /* commands left in the chain buffer */
	{
		j = i; /* initial new iterator to current buf position */
		p = buf + i; /* get ptr for return */

		check_chain(info, buf, &j, i, len);
		while (j < len) /* iterates to semicolon or end */
		{
			if (is_chain(info, buf, &j))
				break;
			j++;
		}

		i = j + 1; /* increment past nulled ';'' */
		if (i >= len) /* reached end of buffer? */
		{
			i = len = 0; /* reset position and len */
			info->cmd_buf_type = CMD_NORM;
		}

		*buf_p = p; /* pass back ptr to current command position */
		return (_strlen(p)); /* return len of current command */
	}

	*buf_p = buf; /* else not a chain pass back buffer from _getline() */
	return (r); /* return len of buffer from _getline() */
}


/**
 * _getline - function get the next line of input from STDIN
 * @info: the parameter structure
 * @ptr: add of pointer to buffer pre_allocated or NULL
 * @length: size of pre_allocated pointer buffer if not NULL
 * Return: s success
 */

int _getline(info_t *info, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p) /* MALLOC FAILURE! */
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*ptr = p;
	return (s);
}



/**
 * sigintHandler - function block ctrl-C
 * @sig_num: signal number
 * Return: nothing
 */

void sigintHandler(__attribute__((unused))int sig_num)
{
_puts("\n");
_puts("$ ");
_putchar(BUF_FLUSH);
}
