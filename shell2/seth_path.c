#include "shell.h"
#include <stdlib.h>
/**
 * set_path - sets Path
 * @new_path: pathe of the directory
 * Return: 0
 */
void set_path(const char *new_path)
{
	if (setenv("PATH", new_path, 1) != 0)
	{
		perror("setenv");
		exit(EXIT_FAILURE);
	}
	else
	{
		_print("PATH set to: %s\n", new_path);
	}
}
