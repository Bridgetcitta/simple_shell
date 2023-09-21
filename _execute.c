#include "shell.h"
#include <unistd.h>

/**
 * _execute - executes commands
 * @command: parameter member
 * Return: 0
 */

void _execute(const char *command)
{
	char *args[2];
	char *envp[] = {NULL};
	char *full_path = "/simple_shell/hsh";

	pid_t child_pid = fork();

	args[0] = (char *)command;
	args[1] = NULL;

	if (command == NULL)
	{
		perror("command is NULL\n");
		return;
	}

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{

		if (execve(full_path, args, envp) == -1)
		{
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
