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
	char *instructions = NULL;

	instruction_t op_instruc[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{NULL, NULL}
	};

	if (stack == NULL || op_token == NULL)
		return (0);
	instructions = op_token;
	for (i = 0; op_instruc[i].opcode; i++)
	{
		if (strcmp(instructions, op_instruc[i].opcode) == 0)
		{
			label = 1;
			op_instruc[i].f(stack, line_number);
			break;
		}
	}
	if (label == 0)
	{
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_no_instruction(op_token, line_number);
	}
	return (0);
}
