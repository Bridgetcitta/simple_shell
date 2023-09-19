#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>

void _prompt(void);
void _print(const char *format);
void read_input(char *format, size_t size);
void _execute(const char *format);
int _atoi(char *s);
int _isalpha(int c);
int interactive(info_t *info);
int _myhelp(info_t *info);
int _mycd(info_t *info);
int _myexit(info_t *info);
int _myalias(info_t *info);
int print_alias(list_t *node);
int set_alias(info_t *info, char *str);
int unset_alias(info_t *info, char *str);
int _myhistory(info_t *info);

#endif
