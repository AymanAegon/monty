#include "monty.h"
#include <string.h>


void check_instruction(char *line, int line_number)
{
    char *opcode, *argument;
    int arg_value;

	opcode = strtok(line, " \t\n");
    if (opcode == NULL)
    	return;
    if (strcmp(opcode, "push") == 0)
    {
        argument = strtok(NULL, " \t\n");
		if (argument == NULL)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
    		exit(EXIT_FAILURE);
		}
		else
		{
			sscanf(argument, "%d", &arg_value);
			push_func(arg_value);
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
    f = fopen(argv[1], "r");
    if (f == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), f) != NULL)
    {
        line_number++;
        check_instruction(line, line_number);
    }
    fclose(f);

    return (0);
}
