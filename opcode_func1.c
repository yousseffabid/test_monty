#include "monty.h"

/**
 * push - add node at the end of double linked list.
 *
 * @stack: pointer to the first node
 * @line_number: data to populate the node
 * Return: the pointer to the new node
 */
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
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the last element of a stack
 *
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 */

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

/**
 * swap - swaps the top two elements of the stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 */

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
