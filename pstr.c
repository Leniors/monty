#include "monty.h"

/**
 * pchar - prints char
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void) line_number;

	current = *stack;
	while (current)
	{
		if (current->n <= 0 || current->n > 127)
		{
			break;
		}
		fprintf(stdout, "%c", current->n);
		current = current->prev;
	}
	fprintf(stdout, "\n");
}
