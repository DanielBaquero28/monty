#include "monty.h"

/**
 * op_push - Pushes the node whether the list is empty or occupied.
 * @stack: Pointer to the top of the stack.
 * @line_number: Error line number if occured.
 * Return: Nothing.
**/

void op_push(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	if (op_token2 == NULL)
	{
		stderr_int_empty(line_number);
		free_stack(*stack);
	}
	if (!is_number() || stack == NULL)
	{
		stderr_int_empty(line_number);
		free_stack(*stack);
	}
	num = atoi(op_token2);
	if (*stack == NULL)
		push_node_empty(stack, num);
	else
		push_node_full(stack, num);
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
	{
		stderr_int_empty(line_number);
		free_stack(*stack);
	}
	if (*stack == NULL)
	{
		free_stack(*stack);
		exit(EXIT_SUCCESS);
	}
	help = *stack;

	while (help->next != NULL)
		help = help->next;
	while (help->prev != NULL)
	{
		printf("%d\n", help->n);
		help = help->prev;
	}
	printf("%d\n", help->n);
}

/**
 * op_pint - Prints the value on the top of the stack.
 * @stack: Points to the top of the stack.
 * @line_number: Line number of where an error can occur.
 * Return: Nothing.
 **/

void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *help;

	if (stack == NULL)
	{
		stderr_pint(line_number);
	}

	if (*stack == NULL)
	{
		stderr_pint(line_number);
	}

	help = *stack;
	while (help->next != NULL)
		help = help->next;

	printf("%d\n", help->n);
}

/**
 * op_pop - Removes the top of the stack.
 * @stack: Points to the bottom of the stack.
 * @line_number: Line number where an error may occur.
 * Return: Nothing.
**/

void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *help = NULL;
	stack_t *temp = NULL;

	if (stack == NULL || *stack == NULL)
	{
		stderr_pop(line_number);
	}

	if ((*stack)->prev == NULL && (*stack)->next == NULL)
	{
		free(*stack);
		(*stack) = NULL;
	}
	else
	{
		help = *stack;
		while (help->next != NULL)
			help = help->next;

		temp = help->prev;
		help->prev = NULL;
		temp->next = NULL;

		free(help);
		help = NULL;
	}
}

/**
 * op_swap - Swaps the first two values of the stack.
 * @stack: Points to the bottom of the stack.
 * @line_number: Line number where an error can occur.
 * Return: Nothing
**/

void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *help;
	stack_t *temp;
	stack_t *temp2;

	int i = 1;

	if (stack == NULL || *stack == NULL)
		stderr_op(line_number, "swap");

	help = *stack;
	while (help->next != NULL)
	{
		help = help->next;
		i++;
	}
	if (i < 2)
		stderr_op(line_number, "swap");
	else
	{
		temp = help->prev;
		temp2 = temp->prev;
		temp->next = NULL;
		help->prev = temp2;
		help->next = temp;
		temp2->next = help;
		temp->prev = help;
	}
}
