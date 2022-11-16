#include "shell.h"
/**
 * hsh_exit - exit built command
 * @args: hold argu
 * Return: 0
 */
void hsh_exit(char **args)
{
	exit(0);
}

/**
 * hsh_cd - cd built commands
 * @args: hold argu
 * Return: 0
 */
void hsh_cd(char **args)
{
	if (args[1] == NULL)
		fprintf(stderr, "hsh: cd: missing argument\n");
	else
	{
		if (chdir(args[1]) != 0)
			perror("hsh: cd");
	}
}

/**
 * hsh_help - help built command
 * @args: hold args
 * Return: 0
 */
void hsh_help(char **args)
{
	char *helptext = "hsh - simple shell work by akrem and neima";

	printf("%s", helptext);
}
