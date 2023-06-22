#include "monty.h"
#include <string.h>

/**
 * check_instruction - check instructions and execute them
 * @stack: stack
 * @line: line of the instruction
 * @line_number: number of the line
 * Return: void
*/
void check_instruction(stack_t **stack, char *line, unsigned int line_number)
{
	char *opcode;
	int i, b = 0;

	opcode = strtok(line, " \t\n");
	if (!opcode)
		return;
	for (i = 0; i < NUMBER_OPCODE; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
			b = 1;
	}
	if (b == 0)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
		free_stack(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	data.arg = strtok(NULL, " \t\n");
	for (i = 0; i < NUMBER_OPCODE; i++)
	{
		if (strcmp(opcode, opcodes[i].opcode) == 0)
		{
			opcodes[i].f(stack, line_number);
		}
	}
}
/**
 * main - monty main code
 * @argc: number of arguments
 * @argv: monty file
 * Return: 0 on success
*/
int main(int argc, char **argv)
{
	char line[256];
	int line_number = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		free_stack(stack);
		exit(EXIT_FAILURE);
	}
	data.file = open_file(argv[1]);
	if (!data.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_stack(stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	create_opcode_arr();
	while (fgets(line, sizeof(line), data.file) != NULL)
	{
		line_number++;
		check_instruction(&stack, line, line_number);
	}
	free_stack(stack);
	fclose(data.file);

	return (0);
}
