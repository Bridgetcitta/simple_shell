#include "shell.h"

/**
 * _execute - executes a commands
 * @format: string input
 * Return: 0
 */

void _execute(const char *format)
{
	pid_t child_pid = fork();
	char path[256];
	char *args[2];
	const char *bin_dir = "/bin/";
	int i, j;

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		for (i = 0; i < 256 && bin_dir[i] != '\0'; i++)
		{
			path[i] = bin_dir[i];
		}

		for (j = 0; i < 256 && format[j] != '\0'; i++, j++)
		{
			path[i] = format[j];
		}
		path[i] = '\0';

		args[0] = (char *)format;
		args[1] = NULL;


		if (execve(path, args, NULL) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	} else
	{
		wait(NULL);
	}
}
