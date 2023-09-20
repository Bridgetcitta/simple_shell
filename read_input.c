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


read_input.c
#include "shell.h"
#include <unistd.h>
#include <string.h>

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
