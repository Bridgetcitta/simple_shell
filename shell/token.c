#include "shell.h"

/**
 * _token - tokenizes arguments
 * @argc: parameter member
 * @argv: array
 * Return: 0
 */

void _token(int argc, char *argv[])
{
	int i;
	char *token;
	char *arg_copy;

	_print("Number of arguments: %d\n", argc);
	_print("Arguments:\n");

	for (i = 0; i < argc; i++)
	{
		_print("%d. %s\n", i + 1, argv[i]);
		_print("Token:\n");

		arg_copy = strdup(argv[i]);
		if (arg_copy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token = strtok(argv[i], " ");

		while (token != NULL)
		{
			_print("%s\n", token);
			token = strtok(NULL, " ");
		}
		free(arg_copy);
	}
}
