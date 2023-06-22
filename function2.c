#include "monty.h"

/**
 * pint_func - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: void
*/
void pint_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
