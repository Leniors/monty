#include "monty.h"

/**
 * main - main function
 * Return: zero on success
 */
int main(int argc, char **argv)
{
	stack_t *stack = NULL;
	stack_t *temp = NULL;
	char line[100];
	int i;
	char opcode[10];
	unsigned int line_number = 0;
	int num_instructions;
	FILE *file = fopen(argv[1], "r");
	char value[10];
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divide},
		{"mul", mul},
		{"mod", mod}
	};

	if (argc != 2)
	{
		fclose(file);
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	global.file = file;
	if (!file)
	{
		fprintf(stderr, "Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file))
	{
		sscanf(line, "%s %s", opcode, value);
		if (opcode[0] == '#')
			return (0);
		line_number++;
		global.value = value;
		num_instructions = sizeof(instructions) / sizeof(instructions[0]);
		for (i = 0; i < num_instructions; i++)
		{
			if (strcmp(opcode, instructions[i].opcode) == 0)
			{
				instructions[i].f(&stack, line_number);
				break;
			}
		}
		if (i == num_instructions)
		{
			fclose(file);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			exit(EXIT_FAILURE);
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
