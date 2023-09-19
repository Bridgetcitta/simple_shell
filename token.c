#include "shell.h"

/**
 * processArguments - handles arguments
 * @argc: parameter member
 * @argv: array
 * Return: 0
 */

void processArguments(int argc, char *argv[])
{
	int i;
	char *token;

	_print("Number of arguments: %d\n", argc);
	_print("Arguments:\n");

	for (i = 0; i < argc; i++)
	{
		_print("%d. %s\n", i + 1, argv[i]);
		_print("Token:\n");
		token = strtok(argv[i], " ");

		while (token != NULL)
		{
			_print("%s\n", token);
			token = strtok(NULL, " ");
		}
	}
}
