#include "shell.h"

/**
 * execute_command - executes by forking a child process and calls execve
 *
 * @args: The command to execute
 * Return: 1 on success, 0 on fail
 */

void execute_command(char **args)
{
	pid_t pid;

	if (!file_exists(args[0]))
	{
		printf("Error: Command not found: %s\n", args[0]);
		return;
	}

	pid = fork();

	if (pid == -1)
	{
		perror("Error: fork process failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{

		if (execve(args[0], args, environ) == -1)
		{
			perror("Error: command execution failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		int status;

		if (waitpid(pid, &status, 0) == -1)
		{
			perror("Error: wait for child process failed");
			exit(EXIT_FAILURE);
		}
	}
}
