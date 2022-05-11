#include "monty.h"
/**
 * interpret_line - interprets line
 * @line: string containing the linei
 * @line_number: number of line
 * @stack: pointer to stack head
 * Return: void
 */

void interpret_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *function_name;
	int valid_or_not;

	function_name = strtok(line, " \t\a\n");
	if (function_name != NULL)
	{
		DATA = strtok(NULL, " \t\a\n");
		valid_or_not = valid(function_name);
		if (valid_or_not != VALID)
		{
			print_error(line, line_number);
			free_stack(stack);
			free(line);
			exit(EXIT_FAILURE);
		}
		else
			exec_func(function_name, line_number, stack);
	}
}
