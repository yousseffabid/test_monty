#include "monty.h"

/**
 * digits - checks if data is only composed of digits
 * @data: string to check
 * Return: 0 onfailure or 1 on success
 */
int digits(char *data)
{
	unsigned int i;

	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[i] < '0' || data[i] > '9')
			return (0);
	}
	return (1);
}

/**
 * valid - checks if th e syntax is valid
 * @function_name: name of the function that can be "push"
 * @data: integer to be pushed if the function is push
 * Return: -1 (push doesn t have an arg) or
 * 0 (function is unknown) on failure and 1 on success
 */
int valid(char *function_name, char *data)
{
	char name[][10] = {"push", "pall", "pint", "pop", "swap", "add", "nop"};
	unsigned int i;

	for (i = 0; i < 7; i++)
	{
		if (strcmp(name[i], function_name) == 0)
		{
			if (i == PUSH)
			{
				if (!digits(data))
					return (-1);
				DATA = atoi(data);
			}
			return (1);
		}
	}
	return (0);
}
