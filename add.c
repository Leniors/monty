#include "monty.h"

/**
 * add - adds up top elements in a stack
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = (*stack)->prev;
	(void)line_number;

	fprintf(stdout, "%d\n", (*stack)->n + temp->n);
}
