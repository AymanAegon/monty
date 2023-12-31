#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>

#define NUMBER_OPCODE 10
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

stack_t *stack;
/**
 * struct data_s - variables -args, file
 * @arg: value
 * @file: pointer to monty file
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *arg;
	FILE *file;
}  data_t;
data_t data;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **head, unsigned int line_number);
void swap_func(stack_t **head, unsigned int line_number);
void add_func(stack_t **head, unsigned int line_number);
void nop_func(stack_t **head, unsigned int line_number);
void sub_func(stack_t **head, unsigned int line_number);
void div_func(stack_t **head, unsigned int line_number);
void mul_func(stack_t **head, unsigned int line_number);
void check_instruction(stack_t **stack, char *line, unsigned int line_number);
void create_opcode_arr();
void free_stack(stack_t *head);
int is_number(char *str);
FILE *open_file(char *str);
int get_argument(char *str);
void free_stack(stack_t *head);
stack_t *push(stack_t **stack, int n);

instruction_t opcodes[NUMBER_OPCODE];
#endif
