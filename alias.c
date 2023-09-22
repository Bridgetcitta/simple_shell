#include "shell.h"
/**
 * printAliases - prints aliases
 * Return: 0
*/

void printAliases(void)
{
	int aliasCount = 0;
	int i;

	for (i = 0; i < aliasCount; i++)
	{
		_print("%s='%s'\n", aliases[i].name, aliases[i].value);
	}
}

/**
 * findAlias - Function to find an alias by name
 * @name: alias pointer
 * Return: 0, -1
 */
int findAlias(char *name)
{
	int i;

	for (i = 0; i < aliasCount; i++)
	{
		if (strcmp(name, aliases[i].name) == 0)
		{
			return (i);
		}
	}
	return (-1);
}

/**
 * extractAlias - Function to extract the alias name and value
 * @arg: parameter member
 * @name: alias poiter
 * @value: ptr
 * Return: 0
 */
int extractAlias(char *arg, char **name, char **value)
{
	char *equalSign = strchr(arg, '=');
	int nameLength = equalSign - arg;
	int valueLength = strlen(arg) - nameLength - 1;

	if (equalSign == NULL)
	{
		return (0);
	}
	*name = malloc(nameLength + 1);
	strncpy(*name, arg, nameLength);
	(*name)[nameLength] = '\0';

	*value = malloc(valueLength + 1);
	strncpy(*value, equalSign + 1, valueLength);
	(*value)[valueLength] = '\0';

	return (1);
}
/**
 * processAlias - Function to handle the alias command
 * @args: array pointer
 * Return: 0, 1
 */
void processAlias(char *args[])
{
	char *name = NULL, *value;
	int index = findAlias(name);
	const char *Err = "alias: Too many aliases\n";
	const char *error = "alias: Invalid syntax\n";

	if (args[1] == NULL)
	{
		printAliases();
	}
	else
	{
		if (extractAlias(args[1], &name, &value))
		{
			if (index != -1)
			{
				free(aliases[index].value);
				aliases[index].value = value;
				free(name);
			}
			else
			{
				if (aliasCount < MAX_ALIASES)
				{
					aliases[aliasCount].name = name;
					aliases[aliasCount].value = value;
					aliasCount++;
				}
				else
				{
					write(STDERR_FILENO, Err, strlen(Err));
					free(name);
					free(value);
				}
			}
		}
		else
		{
			write(STDERR_FILENO, error, strlen(error));
		}
	}
}
