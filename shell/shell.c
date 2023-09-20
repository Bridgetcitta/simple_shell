#include "shell.h"

#define MAX_INPUT_SIZE 256

/**
 * main - entry point
 * @argc: command line argument
 * @argv: array string
 * Return: 0
 */

int main(int argc, char *argv[])
{
	char *format = NULL;
	size_t size = 0;
	const char *newPath = "/path/to/my/directory";

	while (1)
	{
		_prompt();
		format = malloc(sizeof(char) * MAX_INPUT_SIZE);
		if (format == NULL)
		{
			perror("malloc");
			exit(EXIT_FAILURE);
		}
		read_input(format, size);
		_token(argc, argv);
		_execute(format);
		processArguments(argc, argv);
		setPath(newPath);

		free(format);
	}

	return (0);
}
