#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * processArguments - handles arguments
 * @argc: parameter member
 * @argv: parameter member
 * Return: 0
 */

void processArguments(int argc, char *argv[])
{
	int i;

	_print("Number of arguments: %d\n", argc);
	_print("Arguments:\n");

	for (i = 0; i < argc; i++)
	{
		_print("%d. %s\n", i + 1, argv[i]);
	}
}
/**
 * setPath - sets new a path
 * @newPath: string input
 * Return: 0
 */
void setPath(const char *newPath)
{
	if (setenv("PATH", newPath, 1) != 0)
	{
		perror("setenv");
		exit(EXIT_FAILURE);
	}
	else
	{
		_print("%s\n", newPath);
	}
}
/**
 * main - entry point
 * @argc: parameter member
 * @argv: array of string
 * Return: 0
 */
int main(int argc, char *argv[])
{
	const char *newPath;

	processArguments(argc, argv);
	setPath(newpath);

	return (0);
}
