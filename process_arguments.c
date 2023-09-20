#include "shell.h"
#include <stdio.h>
#define MAX_ARGUMENTS 10

/**
 * process_arguments - handles arguments
 * @input: parameter memeber
 * Return: 0
 */
void process_arguments(const char *input)
{
	/* Create a non-const copy of the input */
	char *input_copy;
	char *command = NULL;
	char *arguments[MAX_ARGUMENTS];
	int arg_count = 0;
	char *token = strtok(input_copy, " ");

	strcpy(input_copy, input);

	input_copy = malloc(strlen(input) + 1);
	if (input_copy == NULL)
	{
		perror("memoey allocation failed\n");
		exit(EXIT_FAILURE);
	}

	token = strtok(input_copy, " ");

	while (token != NULL)
	{
		if (arg_count == 0)
		{
		/* The first token is the command. */
		command = token;
		}
		else if (arg_count < MAX_ARGUMENTS)
		{
		/* Store subsequent tokens as arguments.*/
		arguments[arg_count - 1] = token;
		}

		token = strtok(NULL, " ");
		arg_count++;
	}

	/* Null-terminate the arguments array. */
	arguments[arg_count - 1] = NULL;

	free(input_copy);
}
