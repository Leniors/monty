#include "monty.h"

/**
 * push - push element to a stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fclose(global.file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (!global.value)
	{
		fclose(global.file);
		fprintf(stderr, "L%u: usage: push integer", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = global.value;
	new_node->prev = NULL;
	new_node->next = NULL;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		(*stack)->next = new_node;
		new_node->prev = *stack;
		*stack = new_node;
	}
}
