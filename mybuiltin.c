#include "shell.h"

/**
 * _cd - Change current working directory
 * @path: Directory path to change to
 * Return: 0 on success, -1 on failure
 */
int _cd(const char *path)
{
	if (path == NULL)
	{
		/* Change to the home directory if no path is provided */
		path = getenv("HOME");
		if (path == NULL)
		{
			perror("cd");
			return (-1);
		}
	}

	if (chdir(path) == -1)
	{
		perror("cd");
		return (-1);
	}

	/* Update the PWD environment variable */
	if (setenv("PWD", path, 1) == -1)
	{
		perror("setenv");
		return (-1);
	}

	return (0);
}

/**
 * process_cd - Process the cd built-in command
 * @argv: Arguments array
 * Return: 0 on success, -1 on failure
 */
int process_cd(char *argv[])
{
	const char *error_message = "cd: too many arguments\n";

	if (argv[1] == NULL)
	{
		/* Change to the home directory if no argument is provided */
		return (_cd(NULL));
	}
	else if (argv[2] != NULL)
	{
		/* Too many arguments for cd */
		write(STDERR_FILENO, error_message, strlen(error_message));
		return (-1);
	}
	else
	{
		/* Change to the specified directory */
		return (_cd(argv[1]));
	}
}
