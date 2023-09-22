#include "shell.h"

/**
 * custom_atoi - Custom atoi function to convert a string to an integer
 * @str: The string to convert
 * Return: The integer value or -1 on error
 */
int custom_atoi(const char *str)
{
	int result = 0;
	int sign = 1;
	int i = 0;

	/* Handle negative sign */
	if (str[0] == '-')
	{
		sign = -1;
		i = 1;
	}

	 /* Iterate through the string */
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i] - '0');
			i++;
		}
		else
		{
			/* Invalid character encountered */
			return (-1);
		}
	}

	return (result * sign);
}
