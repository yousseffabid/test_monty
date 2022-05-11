#include "monty.h"

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


void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

