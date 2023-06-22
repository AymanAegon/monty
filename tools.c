#include "monty.h"
#include <string.h>

/**
 * get_argument - gets arguments from a str
 * @str: the string
 * Return: int
*/
int get_argument(char *str)
{
	char *argument;

	argument = strtok(str, " \t\n");
	argument = strtok(NULL, " \t\n");
	return (atoi(argument));
}
/**
 * open_file - opens a file
 * @str: name of file
 * Return: FILE
*/
FILE *open_file(char *str)
{
	FILE *f;

	f = fopen(str, "r");
	if (f == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", str);
		exit(EXIT_FAILURE);
	}
	return (f);
}
/**
 * is_number - checks if a string is a number
 * @str: the string
 * Return: 1 if true 0 if not
*/
int is_number(char *str)
{
	if (!str)
		return (0);
	if (*str == '-')
		str++;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		if (*str > '9' || *str < '0')
			if (*str != ' ' && *str != '\t' && *str != '\n')
				return (0);
		str++;
	}
	return (1);
}
