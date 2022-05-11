#include "monty.h"

/**
 * pall - prints the elements of a linked list
 *
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints last item of stack
 *
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
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

