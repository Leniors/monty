#include "monty.h"

/**
 * pall - print stack elements
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	(void)line_number;

	if (current == NULL)
	{
		return;
	}
	while (current)
	{
		fprintf(stdout ,"%d\n", current->n);
		current = current->prev;
	}
}
