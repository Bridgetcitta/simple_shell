#include "shell.h"
#include <unistd.h>

#define MAX_INPUT_SIZE 256

/**
 * main - entry point
 * @argc: command line argument
 * @argv: array of strings
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char input[MAX_INPUT_SIZE];
	const char *new_path = "/simple_shell/";

	while (1)
	{
		_prompt();
		read_input(input, sizeof(input));
		_tokenize_and_print_arguments(argc, argv);
		_execute(input);
		process_arguments(input);
		set_path(new_path);
	}

	return (0);
}
