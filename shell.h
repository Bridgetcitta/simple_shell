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
<<<<<<< HEAD
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
int populate_env_list(info_t *info);
int _myunsetenv(info_t *info);
int _mysetenv(info_t *info);
char *_getenv(info_t *info, const char *name);
int _myenv(info_t *info);
int _putsfd(char *str, int fd);
int _putfd(char c, int fd);
int _eputchar(char c);
void _eputs(char *str);
void remove_comments(char *buf);
char *convert_number(long int num, int base, int flags);
int print_d(int input, int fd);
void print_error(info_t *info, char *estr);
int _erratoi(char *s);
char *_strchr(char *s, char c);
har *_strncat(char *dest, char *src, int n);
int hsh(info_t *info, char **av);
int find_builtin(info_t *info);
void find_cmd(info_t *info);
void fork_cmd(info_t *info);
char *_strchr(char *s, char c);
char *_strncat(char *dest, char *src, int n);
char *_strncpy(char *dest, char *src, int n);
void sigintHandler(__attribute__((unused))int sig_num);
int _getline(info_t *info, char **ptr, size_t *length);
ssize_t read_buf(info_t *info, char *buf, size_t *i);
ssize_t get_input(info_t *info);
ssize_t input_buf(info_t *info, char **buf, size_t *len);
=======
void processArguments(int argc, char *argv[]);
void setPath(const char *newPath);
>>>>>>> 127c13bef45336a5937d6159e0108c787072c70f
#endif
