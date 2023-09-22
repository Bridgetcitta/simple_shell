#include "shell.h"
/**
 * main - entry point
 * Return: 0
 */
int main(void)
{
	char *command = NULL, *arg = NULL, *input = NULL;
	char *arguments[MAX_ARGUMENTS];
	int arg_count = 0, isAliasCommand = 0, i;
	size_t input_size = 0;

	while (1)
	{
		_print("$ ");
		getline(&input, &input_size, stdin);
		for (i = 0; input[i] != '\0'; i++)
		{
			if (input[i] == ' ')
			{
				input[i] = '\0';
				arg = &input[i + 1];
				break;
			}
		}
		if (strcmp(command, "alias") == 0)
		{
			isAliasCommand = 1;
		}
			else if (strcmp(command, "exit") == 0)
			{
				_print("Goodbye!\n");
				break;
			}
		if (isAliasCommand)
			processAlias(&arg);
		else
		{
			if (arg != NULL)
				arguments[arg_count++] = arg;
			arguments[arg_count] = NULL;
			execute_command(arguments);
		}
	}
	free(input);
	return (0);
}
