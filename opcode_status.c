#include "monty.h"

/**
 * opcode_status - Checks if the opcode is for a stack or a queue
 * @stack: Pointer to the top of the stack.
 * Return: 1 if stack else 0 if queue else 2
**/

int opcode_status(stack_t **stack)
{

	if ((*stack)->n == STACK)
		return (1);

	else if ((*stack)->n == QUEUE)
		return (0);

	return (2);
}
