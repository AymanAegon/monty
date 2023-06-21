#include "monty.h"

stack_t *push_func(int argument)
{
    stack_t *new_node = malloc(sizeof(stack_t));

    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }
    new_node->n = argument;
    new_node->next = stack;
    stack = new_node;
    return (new_node);
}

void pall_func()
{
    stack_t *current = stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
