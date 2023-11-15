#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <dirent.h>
#include <sys/wait.h>

extern int op_code_val;
/**
*struct stack_s - doubly linked list representation of a stack (or queue)
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

void err_fn_file(FILE *fp, char *argv);
void err_fn_args(int argc);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int get_opcode(stack_t **stack, char *op_code, unsigned int line_num);
void push_fn(stack_t **stack, unsigned int line_number);
void pall_fn(stack_t **stack, unsigned int line_number);
void start_node(stack_t *stack);

#endif
