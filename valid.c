#include "monty.h"

int valid(char *function_name, char *data)
{
	char name[][10] = {"push", "pall", "pint", "swap", "add", "nop"};
	unsigned int i;

	for (i = 0; i < 5; i++)
	{
		if (strcmp(name[i], function_name) == 0)
		{
			if (name[i] == PUSH)
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
