#include "monty.h"
int op_code_val;

int main(int argc, char **argv)
{
	FILE *fp;
	char *inbuffer = NULL, *token = NULL, *op_code[2];
	size_t inbufsize = 0;
	unsigned int line_num = 1;
	stack_t *stack = NULL;
	int ret;

	err_fn_args(argc);
	fp = fopen(argv[1], "r");
	err_fn_file(fp, argv[1]);
	while (getline(&inbuffer, &inbufsize, fp) != -1)
	{
		token = strtok(inbuffer, " \t");
		op_code[0] = token;
		token = strtok(NULL, " \t");
		op_code[1] = token;
		op_code_val = atoi(op_code[1]);
		if (op_code[0] != NULL && op_code[1] != NULL)
			ret = get_opcode(&stack, op_code[0], line_num);
		if (ret == 0)
		{
			free(inbuffer);
			fclose (fp);
			exit(EXIT_FAILURE);
		}
		line_num++;
	}
	free(inbuffer);
	fclose (fp);
	return(1);
}
