#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_ARGS 10

extern char **environ;

int file_exists(const char *filename);
void execute_command(char **args);

#endif
