#include "monty.h"
/**
 * exec_func - execute function
 * @function_name: name of the function ex: push
 * @line_number: line number of the instruction
 * @stack: pointer to pointer to stack head
 * Return: void
 */
void exec_func(char *function_name, unsigned int line_number, stack_t **stack)
{
	instruction_t code[] = {{"push", push}, {"pall", pall},
							{"pop", pop}, {"pint", pint},
							{"swap", swap}, {"add", add},
							{"nop", nop}, {NULL, NULL}};
	unsigned int i;

	for (i = 0; code[i].opcode != NULL; i++)
	{
		if (strcmp(code[i].opcode, function_name) == 0)
		{
			code[i].f(stack, line_number);
		}
	}
}
