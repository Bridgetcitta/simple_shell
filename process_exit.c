#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * process_exit - Handles the exit built-in command
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, -1 on failure
 */
int process_exit(int argc, char *argv[])
{
	int status;
	const char *error_message = "exit: Illegal number\n";
	const char *error = "exit: too many arguments\n";

	if (argc == 1)
	{
		/* Handle no arguments provided */
		status = 0;
	}
	else if (argc == 2)
	{
		/* Convert the argument to an integer using custom_atoi */
		status = custom_atoi(argv[1]);
		if (status == -1)
		{
			/* Error: Invalid argument */
			write(STDERR_FILENO, error_message, strlen(error_message));
			return (-1);
		}
	}
	else
	{
		/* Too many arguments for exit */
		write(STDERR_FILENO, error, strlen(error));
		return (-1);
	}

	/* Use 'status' as the exit status */
	exit(status);
}
