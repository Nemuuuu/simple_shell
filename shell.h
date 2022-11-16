#ifndef _SHELL_H_
#define _SHELL_H_

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

void hsh_exit(char **args);
void hsh_cd(char **args);
void hsh_help(char **args);

/* A builtin instance associates a command name with a handler function.*/

struct builtin
{
	char *name;
	void (*func)(char **args);
};

/* Array of built in commands.*/

struct builtin builtins[] = {
	{"help", hsh_help},
	{"exit", hsh_exit},
	{"cd", hsh_cd},
};

/**
 * num_builtins - builtin function
 * Return: number of registerd commands
 */
int num_builtins()
{
	return (sizeof(builtins) / sizeof(struct builtin));
}

void exec(char **args);
char **split_line(char *line);
char *read_line();


#endif
