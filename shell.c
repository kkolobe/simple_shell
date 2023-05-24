#include "shell.h"

/**
 * main - Shell
 *
 * Return: 0 on success, else 1
 */

int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
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

		execute_command(line);
	}

	free(line);
	return (0);
}
