#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>

#define MAX_ARGUMENTS 128

void _prompt(void);
void _print(const char *format, ...);
void read_input(char *buffer, size_t size);
void _execute(const char *command);
void process_arguments(const char *input);
void set_path(const char *new_path);
void _tokenize_and_print_arguments(int argc, char *argv[]);

#endif
