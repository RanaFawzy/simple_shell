#include "shell.h"

/**
 * _strlen - returns the length of string,..
 * @s: the string whose length checkk,...
 *
 * Return: integer length of string….
 */
int _strlen(char *s)
{
int i = 0;
if (!s)
return (0);
while (*s++)
i++;
return (i);
}
/**
 * starts_with - checks if needle starts with haystack,...
  * @needle: the substring to find,...
* @haystack: string to search,...
 *
 * Return: address of next char of haystack or NULL
 */
char *starts_with(const char *haystack, const char *needle)
{
while (*needle)
if (*needle++ != *haystack++)
return (NULL);
return ((char *)haystack);
}
/**
 * _strcmp - performs lexicogarphic comparison of 2 strangss,...
 * @s1: the first strangg,...
 * @s2: the second strangg,...
 *
 * Return: negative if s1 < s2, positive if s1 > s2, zero if s1 == s2
 */
int _strcmp(char *s1, char *s2)
{
while (*s1 && *s2)
{
if (*s1 != *s2)
return (*s1 - *s2);
s1++;
s2++;
}
if (*s1 == *s2)
return (0);
else
return (*s1 < *s2 ? -1 : 1);
}
/**
 * _strcat - conccatenates 2 sstrings,..
 * @src: the ssource bufferrr,..
 * @dest: the ddestination bufferrr,..
 *
 * Return: ppointer to destination bufferrr,..
 */
char *_strcat(char *dest, char *src)
{
char *ret = dest;
while (*dest)
dest++;
while (*src)
*dest++ = *src++;
*dest = *src;
return (ret);
}
