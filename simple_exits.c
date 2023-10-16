#include "shell.h"

/**
 * remove_comments - function replace 1st instance of '#' with '\0'
 * @buf: modified string address
 * Return: void
 */

void remove_comments(char *buf)
{
int i;

for (i = 0; buf[i] != '\0'; i++)
	if (buf[i] == '#' && (!i || buf[i - 1] == ' '))
	{
		buf[i] = '\0';
		break;
	}
}


/**
 **_strncat - function used to concatenates 2 strings
 *@dest: 1st string
 *@src: 2nd string
 *@n: maxima number of used bytes
 *Return: string
 */

char *_strncat(char *dest, char *src, int n)
{
	int i, j;
	char *s = dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		dest[i] = '\0';
	return (s);
}


/**
 **_strchr - locates  character in a string
 *@s: str
 *@c: the charact r find
 *Return:  pointr (s)
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}


/**
 **_strncpy - function used to copy  strings
 *@dest: copied str destination
 *@src: str source
 *@n: number of characters to be copied
 *Return: string
 */

char *_strncpy(char *dest, char *src, int n)
{
int i, j;
char *s = dest;

i = 0;
while (src[i] != '\0' && i < n - 1)
{
	dest[i] = src[i];
	i++;
}
if (i < n)
{
	j = i;
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
}
return (s);
}
