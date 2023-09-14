#include "shell.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	char format[128];

	while (1)
	{
		_prompt();
		read_input(format, sizeof(format));
		_execute(format);
	}

	return (0);
}
