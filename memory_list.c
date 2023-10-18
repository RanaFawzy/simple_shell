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
/**
 * list_len - determines length of linked list…
 * @h: pointer first nodee,..
 * Return: size of list,..
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}
