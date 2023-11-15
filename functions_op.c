#include "monty.h"

void push_fn(stack_t **stack, unsigned int line_number)
{
	stack_t *nnode;
	(void) line_number;
       
	nnode = malloc(sizeof(stack_t));
	nnode->n = op_code_val;

	if(*stack == NULL)
	{
		*stack = nnode;
		return;
	}

	nnode->prev = *stack;
	(*stack)->next = nnode;
	(*stack) = nnode;
	printf("%d\n", (*stack)->n);	
}

void pall_fn(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	printf("pall\n");
}
