#include "monty.h"

/**
 * get_opcode - Matches the opcode with it's corresponding function.
 * @stack: Pointer to the top of the stack.
 * @op_token: Opcode token.
 * @line_number: Line number where an error can occur.
 * Return: Nothing.
**/

int *get_opcode(stack_t **stack, char *op_token, unsigned int line_number)
{
	int i, label = 0;

	instruction_t op_instruc[] = {
		{"push", op_push},
		{"pall", op_pall},
		{NULL, NULL}
	};

	if (stack == NULL || op_token == NULL)
		return (0);
	for (i = 0; op_instruc[i].opcode != NULL; i++)
	{
		if (strcmp(op_token, op_instruc[i].opcode) == 0)
		{
			label = 1;
			op_instruc[i].f(stack, line_number);
			break;
		}
	}
	if (label == 0)
		stderr_no_instruction(op_token, line_number);

	return (0);
}
