#include "monty.h"
/**
 * free_stack - execute function
 * @stack: pointer to stack head
 * Return: void
 */

void free_stack(stack_t **stack)
{
	stack_t *ptr, *tmp;

	ptr = *stack;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
	}
}
