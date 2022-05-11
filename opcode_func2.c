#include "monty.h"

/**
 * add - add top two elements and pop
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	int integer;

	(void)line_number;

	if ((*stack)->next == NULL)
	{
		perror("L");
		perror(": can't add, stack too short");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	integer = temp->n;
	*stack = temp->next;
	(*stack)->prev = NULL;
	(*stack)->n = (*stack)->n + integer;
	free(temp);
}


/**
 * nop - doesn't do anything
 *
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 *
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

