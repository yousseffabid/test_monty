#include "monty.h"


/**
 * digits - checks if data is only composed of digits
 * @data: string to check
 * Return: 0 on failure or 1 on success
 */
int digits(char *data)
{
	unsigned int i;

	for (i = 0; data[i] != '\0'; i++)
	{
		if (data[0] == '-' && i == 0)
			continue;
		if (isdigit(data[i]) == 0)
			return (0);
	}
	return (1);
}


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
	if (!digits(DATA))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(DATA);
	new->prev = NULL;
	new->next = NULL;
	if (*stack != NULL)
	{
		new->next = *stack;
		(*stack)->prev = new;
	}
	*stack = new;
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

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = (*stack)->next;
	free(ptr);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	(void)line_number;

	if ((*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;

	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}

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

