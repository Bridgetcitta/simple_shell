#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 256
/**
 * execute_command - executes commands
 * @command: parameter member
 * @arguments: array pointer
 * Return: 0
 */
void execute_command(char *command, char *arguments[])
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		execvp(command, arguments);
		perror("execvp");
		exit(EXIT_FAILURE);
	}
	else
	{
		waitpid(child_pid, &status, 0);
	}
}
