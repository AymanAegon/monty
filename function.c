#include "monty.h"

/**
 * create_opcode_arr - create opcode array
 * 
 * Return: void
*/
void create_opcode_arr()
{
	instruction_t arr[NUMBER_OPCODE] = {
	{"push", push_func},
	{"pall", pall_func},
	{"pint", pint_func}
	};
	int i;

	for (i = 0; i < NUMBER_OPCODE; i++)
		opcodes[i] = arr[i];
}
/**
 * push_func - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: void
*/
void push_func(stack_t **stack, unsigned int line_number)
{
	if (!data.arg || is_number(data.arg) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(data.file);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}

	*stack = push(stack, atoi(data.arg));
}
/**
 * push - add node to the head stack
 * @stack: the stack
 * @n: new value
 * Return: head of the stack
*/
stack_t *push(stack_t **stack, int n)
{
	stack_t *new_node, *head = *stack;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_stack(*stack);
		fclose(data.file);
		exit(EXIT_FAILURE);
	}
	if (head)
		head->prev = new_node;
	new_node->n = n;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
	return (*stack);
}
/**
 * pall_func - prints the stack
 * @stack: stack head
 * @line_number: line_number
 * Return: void
*/
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	line_number++;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
