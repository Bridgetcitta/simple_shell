#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 256
/**
 * execute_command - executes commands
 * @arguments: array pointer
 * Return: 0
 */
void execute_command(char *arguments[])
{
	int status;
	char *envp[] = {NULL};
	char *full_path = "/usr/bin/hsh";

	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		execve(full_path, arguments, envp);
		perror("execve");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
