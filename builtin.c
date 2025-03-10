#include "shell.h"

/**
 * __exit - exits the shell with or without a return of status n
 * @arv: array of words of the entered line
 */
void __exit(char **arv)
{
	if (arv[1])
	{
		exit(_atoi(arv[1]));
	}
	else
	{
		exit(0);
	}
}

/**
 * cd - change directory.
 * @arv: Dir to switch to
 *
 * Return: Nothing
 */
void cd(char **arv)
{
	char *path = arv[1]; /* Retrive path from input array */
	char *dir, *curr_dir;

	/* Check if path is null or "~". assign dir to HOME if so */
	if (path == NULL || _strcmp(path, "~") == 0)
	{
		dir = _getenv("HOME");
	}
	else if (_strcmp(path, "-") == 0) /* Set to prev dir if satisfied */
	{
		dir = _getenv("OLDPWD");
	}
	else
	{
		dir = path; /*Else set dir to provided path */
	}

	curr_dir = getcwd(NULL, 0); /* Get absolute path of current dir */
	if (chdir(dir) != 0)
	{
		write(STDOUT_FILENO, "cd: ", 4);
		write(STDOUT_FILENO, "can't cd to ", 12);
		write(STDOUT_FILENO, dir, _strlen(dir));
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		my_setenv("OLDPWD", curr_dir, 1);
		my_setenv("PWD", getcwd(NULL, 0), 1);
	}
}

/**
 * env - prints the current environment variables
 * @arv: array of words of the entered line
 */
void env(char **arv __attribute__((unused)))
{
	int i;

	/* loop through environ to print all variables */
	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * _setenv - set environment variable or create one.
 * @arv: arry of commands
 *
 * Return: Nothing
 */
void _setenv(char **arv)
{
	if (arv[1] == NULL)
	{
		puts("Usage: setenv VAR VALUE");
		return;
	}
	if (arv[2] == NULL)
	{
		my_unsetenv(arv[1]);
	}
	else
	{
		my_setenv(arv[1], arv[2], 1);
	}
}

/**
 * _unsetenv - unset environment variable
 * @arv: array of entered words
 */
void _unsetenv(char **arv)
{
	if (arv[1] == NULL)
	{
		puts("Usage: unsetenv VAR");
		return;
	}
	my_unsetenv(arv[1]);
}
