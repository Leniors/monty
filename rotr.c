#include "monty.h"

/**
 * rotl - rotates a stack
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current = *stack;
	(void) line_number;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}

	while (current->prev != NULL)
	{
		current = current->prev;
	}

	temp = current;
	current->next->prev = NULL;
	temp->next = NULL;
	temp->prev = *stack;
	(*stack)->next = temp;
	*stack = temp;
	
}
