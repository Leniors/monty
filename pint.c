#include "monty.h"

/**
 * pint - prints top element of the stack
 */
void pint(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	fprintf(stdout, "%d\n", (*stack)->n);
}
