#include "monty.h"

/**
 * main - main function
 * Return: zero on success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	stack_t *temp = NULL;
	FILE *file = fopen(argv[1], "r");
	char line[100];
	int i;
	char opcode[10];
	unsigned int line_number;
	int num_instructions;
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	if (!file)
	{
		fprintf(stderr, "Can't open file %s", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		sscanf(line, "%s %u", opcode, &line_number);
		num_instructions = sizeof(instructions) / sizeof(instructions[0]);
		for (i = 0; i < num_instructions; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}
	}

	fclose(file);

	while (stack)
	{
		temp = stack;
		stack = stack->prev;
		free(temp);
	}

	return (0);
}
