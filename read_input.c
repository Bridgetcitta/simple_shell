#include "shell.h"
#include <unistd.h>
#include <string.h>

/**
 * read_input- reads user input
 * @buffer: string input
 * @size: size of string
 * Return: 0
 */

void read_input(char *buffer, size_t size)
{
	ssize_t bytes_read;

	bytes_read = read(STDIN_FILENO, buffer, size - 1);

	if (bytes_read == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}

	buffer[bytes_read] = '\0';
}
