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
int main(void);
int main(int ac, char **av);
int main(int ac, char **av, char **env);

#endif
