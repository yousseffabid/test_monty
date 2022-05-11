#include "monty.h"

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
