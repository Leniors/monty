#include "monty.h"

/**
 * pint - prints top element of the stack
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	stack_t *current = *stack;
	int num_nodes = 0;

	while (current)
	{
		num_nodes++;
		current = current->prev;
	}
	if (num_nodes == 0)
	{
		fprintf(stderr, "L%d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	fprintf(stdout, "%d\n", (*stack)->n);
}
