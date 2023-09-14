#include "shell.h"

/**
 * _print - prints function
 * @format: string input
 * Return: 0
 */

void _print(const char *format)
{
	write(1, &format, strlen(format));
}
