#include <monty.h>

/**
 * push_node_empty - Pushes a new_node when the list is empty, used as a
 * helper for push opcode function.
 * @stack: Points to the top of the stack.
 * @n: Data (Integer) that will have the new node.
 * Return: New Node.
**/

stack_t *push_node_empty(stack_t **stack, int n)
{
	stack_t new_node = NULL;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	*stack = new_node;
	return (new_node);
}

/**
 * push_node_full - Pushes a new_node to the top of the stac, used as a helper
 * function for push opcode function.
 * @stack: Points to the top of the stack.
 * @n: Data that stores the new_node.
 * Return: New Node.
**/

stack_t *push_node_empty(stack_t **stack, int n)
{
	stack_t new_node;
	stack_t help;

	if (stack == NULL)
		return (NULL);
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	help = *stack;

	while (help->next != NULL)
		help = help->next;

	help->next = new_node;
	new_node->prev = help;
	new_node->next = NULL;

	*stack = new_node;
	return (new_node);
}
