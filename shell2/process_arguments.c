#include "shell.h"
#include <stdio.h>
/**
 * process_arguments - handles arguments
 * @input: parameter memeber
 * Return: 0
 */
void process_arguments(const char *input)
{
	char *input_copy = NULL;
	char *command = NULL;
	char *arguments[MAX_ARGUMENTS];
	int arg_count = 0;
	int i;
	char *token = strtok(input_copy, " ");

	if (input != NULL)
	{
		input_copy = malloc(strlen(input) + 1);
		if (input_copy == NULL)
		{
		perror("memoey allocation failed\n");
		exit(EXIT_FAILURE);
		}
		strcpy(input_copy, input);
	}
	token = strtok(input_copy, " ");
	while (token != NULL)
	{
		if (arg_count == 0)
		{
		command = token;
		}
		else if (arg_count < MAX_ARGUMENTS)
		{
		arguments[arg_count - 1] = token;
		}

		token = strtok(NULL, " ");
		arg_count++;
	}
	arguments[arg_count - 1] = NULL;
	_print("command: %s\n", command);
	_print("arguments:\n");
	for (i = 0; i < arg_count - 1; i++)
	{
		_print("%d. %s\n", i + 1, arguments[i]);
	}
	free(input_copy);
}
