#include "monty.h"

int get_opcode(stack_t **stack, char *op_code, unsigned int line_num)
{
	int i = 0;
	int found = 0;

	instruction_t functions[] = {
		{"push", push_fn}, 
		{"pall", pall_fn},
		{NULL, NULL}};	

	while (functions[i].opcode != NULL)
	{
		if (strcmp(functions[i].opcode, op_code) == 0)
		{
			functions[i].f(stack, line_num);
			found = 1;
			break;
		}
		i++;
	}
	if (!found)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op_code);
		return (0);
	}
	return (1);
}
