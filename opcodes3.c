#include "monty.h"

/**
 * op_mod - Divides the second top element of the stack by
 * the top element of the stack and finds the remainder.
 * @stack: Pointer to the bottom of the stack.
 * @line_number: Line number.
 * Return: Nothing
 **/

void op_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *help;
	stack_t *temp;
	int i = 1;

	if (stack == NULL || *stack == NULL)
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_op(line_number, "mod");
	}
	help = *stack;
	while (help->next != NULL)
	{
		help = help->next;
		i++;
	}
	if (i < 2)
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_op(line_number, "mod");
	}
	else if (help->n == 0)
	{
		fprintf(stderr, "L<%d>: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = help->prev;
		temp->n %= help->n;
		temp->next = NULL;
		help->prev = NULL;
		free(help);
		help = NULL;
	}
}
