#include "shell.h"
/**
 * read_line - Read a single line of input from
 *
 * Return: string pointer
 */
char *read_line(void)
{
	char *line = NULL;
	size_t buflen = 0;

	errno = 0;
	ssize_t strlen = getline(&line, &buflen, stdin);

	if (strlen < 0)
	{
		if (errno)
			perror("hsh");
		exit(1);
	}
	return (line);
}
