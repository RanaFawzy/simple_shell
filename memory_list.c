#include "shell.h"

/**
 * bfree - frees pointer and NULLs to address,...
 * @ptr: address of the pointer free,...
 *
 * Return: 1 if freed, otherwise 0.
 */
int bfree(void **ptr)
{
if (ptr && *ptr)
{
free(*ptr);
*ptr = NULL;
return (1);
}
return (0);
}