#include "monty.h"

/**
 * op_add - Adds the top nodes of the stack.
 * @stack: Points to the bottom of the stack.
 * @line_number: Line number where an error can occur.
 * Return: Nothing.
**/

void op_add(stack_t **stack, unsigned int line_number)
{
	stack_t *help;
	stack_t *temp;
	int i = 1;

	if (stack == NULL || *stack == NULL)
		stderr_op(line_number, "add");

	help = *stack;
	while (help->next != NULL)
	{
		help = help->next;
		i++;
	}
	if (i < 2)
		stderr_op(line_number, "add");

	else
	{
		temp = help->prev;
		temp->n += help->n;
		temp->next = NULL;
		help->prev = NULL;
		free(help);
		help = NULL;
	}
}

/**
 * op_nop - Doesn't do anything.
 * @stack: Points to the bottom of the stack.
 * @line_number: Line number where an error can occur.
 * Return: Nothing.
**/

void op_nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
