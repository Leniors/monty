#include "monty.h"

/**
 * rotl - rotates a stack
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	stack_t *current = *stack;
	(void) line_number;

	while (current->prev != NULL)
	{
		current = current->prev;
	}

	*stack = (*stack)->prev;
	(*stack)->next = NULL;
	current->prev = temp;
	temp->prev = NULL;
}
