#include "shell.h"

/**
 * _memset - fills memory with constant byte,...
 * @s: the pointer to memory areaa,.,.,.
 * @n: the amount of bytes to be filleddd,.,....
 * @b: the byte fill *s with,,,
 * Return: (s) a pointer to the memory area s,,,
 */
char *_memset(char *s, char b, unsigned int n)
{
unsigned int i;
for (i = 0; i < n; i++)
s[i] = b;
return (s);
}
/**
 * _realloc - reallocates block of memoryy,.,...
 * @ptr: pointer previous malloc'ated block,,,,
 * @old_size: byte size previous block,,,,
 * @new_size: byte size new block,,,,
 *
 * Return: pointer da ol'block nameenn…...
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
char *p;
if (!ptr)
return (malloc(new_size));
if (!new_size)
return (free(ptr), NULL);
if (new_size == old_size)
return (ptr);
p = malloc(new_size);
if (!p)
return (NULL);
old_size = old_size < new_size ? old_size : new_size;
while (old_size--)
p[old_size] = ((char *)ptr)[old_size];
free(ptr);
return (p);
}
/**
 * ffree - frees string of stringss….
 * @pp: string of stringss,,,
 */
void ffree(char **pp)
{
char **a = pp;
if (!pp)
return;
while (*pp)
free(*pp++);
free(a);
}
