#include "shell.h"
/**
 * exec - Process/command launcher.
 * @args: hold argument
 * Return: 0
 */
void exec(char **args)
{
	for (int i = 0; i < num_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			return;
		}
	}
	pid_t child_pid = fork();

	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("hsh");
		exit(1);
	}
	else if (child_pid > 0)
	{
		int status;

		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("hsh");
	}
}
