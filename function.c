#include <stdio.h>
#include <stdlib.h>

typedef struct stack_node
{
    int value;
    struct stack_node *next;
} StackNode;

StackNode *stack = NULL;

void push_func(int argument, int line_number)
{
    StackNode *new_node = malloc(sizeof(StackNode));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = argument;
    new_node->next = stack;
    stack = new_node;
}

void pall_func()
{
    StackNode *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->value);
        current = current->next;
    }
}
