#include "shell.h"

/**
 * file_exists - Checks whether a file is present.
 *
 * @filename: This is the name of the file to check.
 * Return: 1 if the file is there, else 0
 */

int file_exists(const char *filename)
{
	struct stat buffer;

	return (stat(filename, &buffer) == 0);
}
