#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>
#include <unistd.h>

#define MAX_ALIASES 100
#define MAX_INPUT_SIZE 256
#define MAX_ARGUMENTS 128

<<<<<<< HEAD
=======
<< << << < HEAD
/* Structure to store aliases */
struct Alias
== == == =
>>>>>>> f8c2f3cd3f53b0771381ff2ddfee5f76c63616a4
/**
 * struct Alias - Structure to store aliases
 * @name: name
 * @value: value
 */
<<<<<<< HEAD
struct Alias
{
	char *name;
	char *value;
};

struct Alias aliases[MAX_ALIASES];
=======
typedef struct Alias
>> >> >> > 0d70d98fd700baf2df62da0ec2808a4a74b3ced2
{
	char *name;
	char *value;
}
/* Global array to store aliases */
struct Alias aliases[MAX_ALIASES]
<< << << < HEAD
int aliasCount
== == == =
>> >> >> > 0d70d98fd700baf2df62da0ec2808a4a74b3ced2
>>>>>>> f8c2f3cd3f53b0771381ff2ddfee5f76c63616a4
void printAliases(void);
int findAlias(char *name);
int extractAlias(char *arg, char **name, char **value);
void processAlias(char *args[]);
void _print(const char *format, ...);
void execute_command(char *arguments[]);
int check_command_existence(char *command);
ssize_t custom_getline(char **lineptr, size_t *n, FILE *stream);
void shell_exit(int status);
int shell_setenv(char *name, char *value, int overwrite);
int shell_unsetenv(char *name);
int _cd(const char *path);
int process_cd(char *argv[]);
int process_exit(int argc, char *argv[]);
int custom_atoi(const char *str);

#endif
