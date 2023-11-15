#include "monty.h"

void push_fn(stack_t **stack, unsigned int line_number)
{
	stack_t *nnode;
	(void) line_number;
       
	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	nnode->n = op_code_val;

	if(*stack == NULL)
	{
		nnode->prev = NULL;
		nnode->next = NULL;
		*stack = nnode;
		free(nnode);
		return;
	}

	nnode->prev = *stack;
	(*stack)->next = nnode;
	(*stack) = nnode;
	free(nnode);
	/*printf("%d\n", (*stack)->n);*/
}

void pall_fn(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
	/*printf("pall\n");*/
}
