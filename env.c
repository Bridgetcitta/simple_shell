#include "shell.h"

#include <stdio.h>
#include <stdlib.h>
/**
 * shell_setenv - sets environment for the shell
 * @name: parameter pointer
 * @value: parameter member
 * @overwrite: integer input
 * Return: 0 if success, -1 if failure
 */
int shell_setenv(char *name, char *value, int overwrite)
{
	if (setenv(name, value, overwrite) == 0)
	{
		return (0); /* Success */
	}
	return (-1); /* Failure */
}
/**
 * shell_unsetenv - unsets an environment for a shell
 * @name: Parameter member
 * Return: 0 if success, -1 if failure
 */
int shell_unsetenv(char *name)
{
	if (unsetenv(name) == 0)
	{
		return (0); /* Success */
	}
	return (-1); /* Failure */
}
