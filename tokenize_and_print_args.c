#include "shell.h"
#include <string.h>
/**
 * _tokenize_and_print_arguments - tokenize and prints arguments
 * @argc: command line arguments
 * @argv: array of strings
 * Return: 0
 */
void _tokenize_and_print_arguments(int argc, char *argv[])
{
	int i;
	char *token;
	char *arg_copy = NULL;

	_print("Number of arguments: %d\n", argc);
	_print("Arguments:\n");

	for (i = 0; i < argc; i++)
	{
		_print("%d. %s\n", i + 1, argv[i]);
		_print("Tokenized Arguments:\n");

		arg_copy = strdup(argv[i]);

		if (arg_copy == NULL)
		{
			perror("strdup");
			exit(EXIT_FAILURE);
		}

		token = strtok(arg_copy, " ");
		while (token != NULL)
		{
			_print("%s\n", token);
			token = strtok(NULL, " ");
		}

		free(arg_copy);
	}
}
