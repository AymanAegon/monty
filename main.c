#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void push_func(int argument, int line_number);
void pall_func();

void check_instruction(char *line, int line_number)
{
    char *opcode = strtok(line, " \t\n");

    if (opcode != NULL)
    {
        if (strcmp(opcode, "push") == 0)
        {
            char *argument = strtok(NULL, " \t\n");
            if (argument == NULL)
            {
                fprintf(stderr, "L%d: usage: push integer\n", line_number);
                exit(EXIT_FAILURE);
            }
            else
            {
                int arg_value;
                sscanf(argument, "%d", &arg_value);
                push_func(arg_value, line_number);
            }
        }
        else if (strcmp(opcode, "pall") == 0)
        {
            pall_func();
        }
        else
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            exit(EXIT_FAILURE);
        }
    }
}

int main(int argc, char **argv)
{
    FILE *f;
    char line[256];
    int line_number = 0;
    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        f = fopen(argv[1], "r");
        if (f == NULL)
        {
            fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        else
        {
            while (fgets(line, sizeof(line), f) != NULL)
            {
                line_number++;
                check_instruction(line, line_number);
            }
        }
        fclose(f);
    }
    return 0;
}
