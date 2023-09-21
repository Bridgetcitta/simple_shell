#include "shell.h"
#include <stdarg.h>
#include <unistd.h>
/**
 * _print - custom printf-like function
 * @format: format string
 * @...: variable arguments
 */
void _print(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	vfprintf(stdout, format, args);

	va_end(args);
}

/**
 * print_char - prints a character
 * @c: character to print
 */
void print_char(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/**
 * print_str - prints a string
 * @str: pointer to the string to print
 */
void print_str(const char *str)
{
	if (str != NULL)
	{
		write(STDOUT_FILENO, str, strlen(str));
	}
	else
	{
		print_str("(null)");
	}
}

/**
 * print_int - prints an integer
 * @num: integer to print
 */
void print_int(int num)
{
	char int_str_buffer[12];
	int len = 0;
	int i;

	if (num == 0)
	{
		int_str_buffer[len++] = '0';
	}
	else
	{
		while (num > 0)
		{
			int_str_buffer[len++] = '0' + (num % 10);
			num /= 10;
		}
	}

	for (i = len - 1; i >= 0; i--)
	{
		print_char(int_str_buffer[i]);
	}
}
