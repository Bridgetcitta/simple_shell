#include "shell.h"
/**
 * _print - prints function
 * @format: string input
 * Return: 0
 */
void _print(const char *format, ...)
{
	int num, i;
	int len = 0;
	char num_str[12];
	char *str;
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
				while (num > 0)
				{
					num_str[len++] = '0' + (num % 10);
					num /= 10;
				}
				if (len == 0)
				{
					num_str[len++] = '0';
				}
				for (i = len - 1; i >= 0; i--)
				{
					write(1, &num_str[i], 1);
				}
			}
			else if (*format == 's')
			{
				str = va_arg(args, char *);
				while (*str)
				{
					write(1, str, 1);
					str++;
				}
			}
		}
		else
		{
			write(1, format, 1);
		}
		format++;
	}
	va_end(args);
}
