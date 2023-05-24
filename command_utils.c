#include "shell.h"

/**
 * execute_command - executes by forking a child process and calls execve
 *
 * @line: The command to execute
 * Return: 1 on success, 0 on fail
 */

void execute_command(char *line)
{
	pid_t pid;
	char *args[2];

	if (!file_exists(line))
	{
		printf("Error: Command not found: %s\n", line);
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
		args[0] = line;
		args[1] = NULL;

		if (execve(line, args, environ) == -1)
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
