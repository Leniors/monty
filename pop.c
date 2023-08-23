#include "monty.h"

/**
 * pop - remove top element of a stack
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void)line_number;

	*stack = (*stack)->prev;
	free(temp);
}
