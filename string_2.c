#include "shell.h"

/**
 * _strncmp - compare strings to atmost n
 * @s1: string 1
 * @s2: string 2
 * @n: number of bytes to compare
 *
 * Return: Compared difference
 */

int _strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- > 0 && *s1 && *s2)
	{
		if (*s1 != *s2)
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	if (n == (size_t) -1)
		return (0);
	return ((*s1 ? 1 : 0) - (*s2 ? 1 : 0));
}

/**
 * _strlen - custom strlen function
 * @str: input string
 *
 * Return: string length
 */

size_t _strlen(const char *str)
{
	size_t len = 0;

	while (str[len] != '\0')
	{
		len++;
	}
	return (len);
}
