#include "shell.h"
/**
 * main - Entry point
 *
 * Return: 0
 */
int main(void)
{
	while (true)
	{
		printf("$ ");
		char *line = read_line();
		char **tokens = split_line(line);

		if (tokens[0] != NULL)
		{
			exec(tokens);
		}

		free(tokens);
		free(line);
	}
}
