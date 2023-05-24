#include "shell.h"

/**
 * main - Shell
 *
 * Return: 0 on success, else 1
 */

int main(void)
{
	while (1)
	{
		char *line = NULL;
		size_t len = 0;
		ssize_t read;

		char *token;
		char **args = malloc(sizeof(char *) * MAX_ARGS);
		int arg_count = 0;

		write(1, "& ", 2);
		read = getline(&line, &len, stdin);

		if (read == -1 && errno == EINTR)
		{
			continue;
		}
		else if (read == -1 && errno == EINVAL)
		{
			perror("Error: invalid arguments passed to getline");
			exit(EXIT_FAILURE);
		}
		else if (read == -1)
		{
			exit(EXIT_FAILURE);
		}
		else if (read == 0)
		{
			break;
		}
		if (line[read - 1] == '\n')
		{
			line[read - 1] = '\0';
		}

		token = strtok(line, " ");
		while (token != NULL && arg_count < MAX_ARGS)
		{
			args[arg_count] = token;
			arg_count++;
			token = strtok(NULL, " ");
		}
		args[arg_count] = NULL;

		execute_command(args);

		free(args);
		free(line);
	}

	return (0);
}
