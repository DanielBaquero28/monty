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
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_op(line_number, "add");
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
		stderr_op(line_number, "add");
	}
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

/**
 * op_sub - Substracts the top of the stack from the second top element.
 * @stack: Pointer to the bottom of the stack.
 * @line_number: Line number.
 * Return: Nothing
**/

void op_sub(stack_t **stack, unsigned int line_number)
{
	stack_t *help;
	stack_t *temp;
	int i = 1;

	if (stack == NULL || *stack == NULL)
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_op(line_number, "sub");
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
		stderr_op(line_number, "sub");
	}
	else
	{
		temp = help->prev;
		temp->n -= help->n;
		temp->next = NULL;
		help->prev = NULL;
		free(help);
		help = NULL;
	}
}

/**
 * op_div - Divides the second top element of the stack by
 * the top element of the stack.
 * @stack: Pointer to the bottom of the stack.
 * @line_number: Line number.
 * Return: Nothing
**/

void op_div(stack_t **stack, unsigned int line_number)
{
	stack_t *help;
	stack_t *temp;
	int i = 1;

	if (stack == NULL || *stack == NULL)
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_op(line_number, "div");
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
		stderr_op(line_number, "div");
	}
	else if (help->n == 0)
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		fprintf(stderr, "L<%d>: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		temp = help->prev;
		temp->n /= help->n;
		temp->next = NULL;
		help->prev = NULL;
		free(help);
		help = NULL;
	}
}

/**
 * op_mul - Substracts the top of the stack from the second top element.
 * @stack: Pointer to the bottom of the stack.
 * @line_number: Line number.
 * Return: Nothing
**/

void op_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *help;
	stack_t *temp;
	int i = 1;

	if (stack == NULL || *stack == NULL)
	{
		free(gbl.line);
		free_stack(*stack);
		fclose(gbl.m_file);
		stderr_op(line_number, "mul");
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
		stderr_op(line_number, "mul");
	}
	else
	{
		temp = help->prev;
		temp->n *= help->n;
		temp->next = NULL;
		help->prev = NULL;
		free(help);
		help = NULL;
	}
}
