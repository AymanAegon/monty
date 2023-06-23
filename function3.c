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
	int len = 0, a;

	while (head)
	{
		len++;
		head = head->next;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short", line_number);
		free_stack(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	a = head->next->n - head->n;
	head->next->n = a;
	*stack = head->next;
	free(head);
}
