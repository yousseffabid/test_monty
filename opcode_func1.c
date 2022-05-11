#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	(void)line_number;

	if (stack == NULL)
		return;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	new->n = DATA;
	new->prev = NULL;
	if (*stack != NULL)
		(*stack)->prev = new;

	new->next = *stack;
	*stack = new;
}


void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}


void pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}


void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	if ((*stack)->next != NULL)
		*stack = (*stack)->next;
	else
		*stack = NULL;
	free(ptr);
}


void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	(void)line_number;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = (*stack)->next;

	second->prev = NULL;
	first->prev = second;

	first->next = second->next;
	(second->next)->prev = first;
	second->next = first;

	*stack = second;
}
