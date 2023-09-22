#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
/**
 * custom_getline - is a custom getline function
 * @lineptr: pointer to character
 * @n: size of buffer
 * @stream: a file stream
 * Return: 0
 */
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream)
{
	int ch;
	size_t len = 0;

	(void)stream; /* intentionally left here */

	if (*lineptr == NULL || *n == 0)
	{
		*n = 128; /* Initial buffer size */
		*lineptr = (char *)malloc(*n);
		if (*lineptr == NULL)
		{
			return (-1); /* Allocation error */
		}
	}

	while (1)
	{
		ch = getchar();
		if (ch == EOF || ch == '\n')
		{
			(*lineptr)[len] = '\0';
			return (len); /* Return the length of the line */
		}

		(*lineptr)[len] = ch;
		len++;

		/* Resize the buffer if needed */
		if (len >= *n)
		{
			*n *= 2;
			*lineptr = (char *)realloc(*lineptr, *n);
			if (*lineptr == NULL)
			{
				return (-1); /* Allocation error */
			}
		}
	}
}
