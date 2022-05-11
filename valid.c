#include "monty.h"
/**
 * valid - checks if th e syntax is valid
 * @function_name: name of the function that can be "push"
 * @data: integer to be pushed if the function is push
 * Return: -1 (push doesn t have an arg) or 0 (function is unknown) on failure and 1 on success
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
				DATA = atoi(data);
				if (data[0] != '0' && DATA == 0)
					return (-1);
			}
			return (1);
		}
	}
	return (0);
}
