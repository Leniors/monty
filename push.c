#include "monty.h"

/**
 * push - push element to a stack
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int i;

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fclose(global.file);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (is_integer(global.value) != true)
	{
		fclose(global.file);
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	i = atoi(global.value);
	new_node->n = i;
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
