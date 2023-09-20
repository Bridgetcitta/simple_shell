#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <stdarg.h>

void _prompt(void);
void _print(const char *format, ...);
void read_input(char *format, size_t size);
void _execute(const char *format);
void processArguments(int argc, char *argv[]);
void setPath(const char *newPath);
void _token(int argc, char *argv[]);
void _print(const char *format, ...);
void print_char(char c);
void print_str(const char *str);
void print_int(int num);


#endif
