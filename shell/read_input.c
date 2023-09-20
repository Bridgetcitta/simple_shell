#include "shell.h"

/**
 * read_input - reads input
 * @format: string input
 * @size: size of string
 * Return: 0
 */

void read_input(char *format, size_t size)
{
	ssize_t bytes_read;


	bytes_read = read(STDIN_FILENO, format, size);

	if (bytes_read == -1)
	{
		perror("read");
		exit(EXIT_FAILURE);
	}
	format[bytes_read - 1] = '\0';
}
