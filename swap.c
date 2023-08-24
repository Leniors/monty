#include "monty.h"

/**
 * swap - swap elements at the top of the stack
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current = *stack;
	int num_nodes = 0;

	while (current)
	{
		num_nodes++;
		current = current->prev;
	}
	if (num_nodes < 3)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->prev;
	(*stack)->prev = temp->prev;
	temp->prev->next = *stack;
	(*stack)->next = temp;
	temp->prev = *stack;
	*stack = temp;
}
