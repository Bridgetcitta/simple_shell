#include "shell.h"

/**
 * print_char - prints a character
 * @c: character to print
 */
void print_char(char c)
{
	write(1, &c, 1);
}

/**
 * print_str - prints a string
 * @str: pointer to the string to print
 */
void print_str(const char *str)
{
	if (str != NULL)
	{
		while (*str)
		{
			print_char(*str);
			str++;
		}
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

/**
 * _print - custom printf-like function
 * @format: format string
 * @...: variable arguments
 */
void _print(const char *format, ...)
{
	int num;
	const char *str;
	va_list args;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%' && *(format + 1) != '\0')
		{
			format++;
			if (*format == 'd')
			{
				num = va_arg(args, int);
				print_int(num);
			}
			else if (*format == 's')
			{
				str = va_arg(args, const char *);
				print_str(str);
			}
		}
		else
		{
			print_char(*format);
		}
		format++;
	}

	va_end(args);
}

