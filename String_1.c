#include "shell.h"

/**
 * _strcpy - copies string,...
 * @src: the source,,,,,
 * @dest: the destination,,,,,
 *
 * Return: pointer to destination,.,.,...
 */
char *_strcpy(char *dest, char *src)
{
int i = 0;
if (dest == src || src == 0)
return (dest);
while (src[i])
{
dest[i] = src[i];
i++;
}
dest[i] = 0;
return (dest);
}
/**
 * _putchar - writes the character c to the stdout,...
 * @c: The character to print,...
 * On error, -1 is returned, and errno is set appropriately.,....
 * Return: On success 1.,...
 */
int _putchar(char c)
{
static int i;
static char buf[WRITE_BUF_SIZE];
if (c == BUF_FLUSH || i >= WRITE_BUF_SIZE)
{
write(1, buf, i);
i = 0;
}
if (c != BUF_FLUSH)
buf[i++] = c;
return (1);
}
/**
 * _strdup - duplicates string,.....
 * @str: the string duplicate,.,....
 *
 * Return: pointer to duplicated string,,,,
 */
char *_strdup(const char *str)
{
int length = 0;
char *ret;
if (str == NULL)
return (NULL);
while (*str++)
length++;
ret = malloc(sizeof(char) * (length + 1));
if (!ret)
return (NULL);
for (length++; length--;)
ret[length] = *--str;
return (ret);
}
