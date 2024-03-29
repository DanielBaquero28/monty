#include "monty.h"

char *op_token2 = NULL;
global_t gbl = {NULL, NULL};

/**
 * main - Entry point of all the program, calls the other functions made.
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: EXIT_FAILURE if an error occurs, or else EXIT_SUCCESS.
**/

int main(int argc, char **argv)
{
	int line_number = 0, label = 0, label2= 0;
	char *op_token = NULL;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read;

	gbl.line = NULL;
	if (argc != 2)
		stderr_file_usage();
	gbl.m_file = fopen(argv[1], "r");
	if (gbl.m_file == NULL)
		stderr_fopen_file(argv[1]);
	read = getline(&(gbl.line), &len, gbl.m_file);
	    if (gbl.line[0] == '#')
		    read = getline(&(gbl.line), &len, gbl.m_file);
	while (read != -1)
	{label = 0;
		label2 = 0;
		line_number++;
		op_token = strtok(gbl.line, " \n\a\t\0");
		op_token2 = strtok(NULL, " \n\a\t\0");
		if (op_token == NULL)
		{label2 = 1;
			op_nop(&stack, line_number); }
		if (label2 == 0)
		{
			if (op_token[0] == '#')
			{read = getline(&(gbl.line), &len, gbl.m_file);
				label = 1; }}
		if (label == 0)
		{get_opcode(&stack, op_token, line_number);
			read = getline(&(gbl.line), &len, gbl.m_file); }}
	free(gbl.line);
	free_stack(stack);
	gbl.line = NULL;
	fclose(gbl.m_file);
	exit(EXIT_SUCCESS);
}
