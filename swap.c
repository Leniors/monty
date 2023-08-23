#include "monty.h"

/**
 * swap - swap elements at the top of the stack
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	(void)line_number;

	temp = (*stack)->prev;
	(*stack)->prev = temp->prev;
	temp->prev->next = *stack;
	(*stack)->next = temp;
	temp->prev = *stack;
	*stack = temp;
}
