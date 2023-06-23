#include "monty.h"

/**
 * sub_func - subtracts the top element from the second top element
 * @stack: stack head
 * @line_number: line_number
 * Return: void
*/
void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *head = *stack;
	int a, b = 0;

	if (head)
	{
		a = head->n;
		head = head->next;
	}
	if (head)
	{
		a = head->n - a;
		b = 1;
	}
	if (b == 0)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		free_stack(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	pop_func(stack, line_number);
	pop_func(stack, line_number);
	push(stack, a);
}
