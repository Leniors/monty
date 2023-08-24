#include "monty.h"

/**
 * add - adds up top elements in a stack
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;
	stack_t *current = *stack;
	int num_nodes = 0;

	while (current)
	{
		num_nodes++;
		current = current->prev;
	}

	if (num_nodes < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	*stack = (*stack)->prev;
	(*stack)->n = temp->n + (*stack)->n;
	free(temp);
}
