#include "monty.h"

/**
 * create_stack - Creates a stack from which we will save our nodes..
 * @stack: Pointer to the top of the stack.
 * Return: If successful, EXIT SUCCESS
**/

int create_stack(stack_t **stack)
{
	stack_t *new_stack;

	new_stack = malloc(sizeof(stack_t));

	if (new_stack == NULL)
		stderr_failed_malloc();

	new_stack->n = STACK;
	new_stack->next = NULL;
	new_stack->prev = NULL;

	*stack = new_stack;
	return (EXIT_SUCCESS);
}

/**
 * free_stack - Frees all of the nodes of the stack.
 * @stack: Points to the top of the stack.
 * Return: Nothing.
**/

void free_stack(stack_t *stack)
{
	stack_t *help;
	stack_t *temp;

	help = stack;
	while (help != NULL)
	{
		temp = help->next;
		free(help);
		help = temp;
	}
	stack = NULL;
}
