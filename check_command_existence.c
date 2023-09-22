#include "shell.h"
#include <unistd.h>

/**
 * check_command_existence - checks command
 * @command: parameter memmber
 * Return: 0
 */

int check_command_existence(char *command)
{
	if (access(command, X_OK) == 0)
	{
		return (1); /* Command exists */
	}
	return (0); /* Command does not exist */
}
