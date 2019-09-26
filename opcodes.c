#include "monty.h"

/**
 * op_push - Pushes the node whether the list is empty or occupied.
 * @stack: Pointer to the top of the stack.
 * @line_number: Error line number if occured.
 * Return: Nothing.
**/

void op_push(stack_t **stack, unsigned int line_number)
{
	int n;

	if (!is_number() || op_token2 == NULL || stack == NULL)
		stderr_int_empty(line_number);

	n = atoi(op_token2);
	if (*stack == NULL)
		push_node_empty(stack, n);
	else
		push_node_full(stack, n);
}

/**
 * op_pall - Prints all of the objects that are contained in the stack.
 * @stack: Pointer to the top of the stack.
 * @line_number: Error line number if occured.
 * Return: Nothing.
**/

void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *help = NULL;

	if (stack == NULL)
		stderr_int_empty(line_number);
	if (*stack == NULL)
		exit(EXIT_SUCCESS);

	help = *stack;

	while (help->prev != NULL)
	{
		printf("%d\n", help->n);
		help = help->prev;
	}
	if (help->prev == NULL)
		printf("%d\n", help->n);
}
