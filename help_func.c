#include "monty.h"

/**
 * token_length - Length for the token opcode's argument.
 * Return: Token's length.
**/

unsigned int token_length(void)
{
	unsigned int len;

	len = 0;
	while (op_token2[len])
		len++;

	return (len);
}
/**
 * token_error - Reviews the op_token2 and sets the last
 * instruction as an error code.
 * @stat_error: Error status returning when reviewing op_token2.
 * Return: Nothing.
**/

void token_error(int stat_error)
{
	int len = 0;
	int i;
	char *string = NULL;
	char *new_node = NULL;

	len = token_length();
	new_node = malloc(sizeof(char *) *(len + 2));
	if (new_node == NULL)
		stderr_failed_malloc();
	if (op_token2 == NULL)
	{
		stderr_failed_malloc();
		return;
	}
	i = 0;
	while (i < len)
	{
		new_node[i] = op_token2[i];
		i++;
	}
	string = change_to_str(stat_error);
	if (!string)
	{
		free(op_token2);
		stderr_failed_malloc();
		return;
	}
	free(op_token2);
	op_token2 = new_node;
}

/**
 * is_number - Checks if it's a number or not.
 * Return: 1 is True or 0 if false.
**/

int is_number(void)
{
	int i;

	i = 0;
	if (op_token2[i] == '-')
		i++;

	while (op_token2)
	{
		if (op_token2[i] >= '0' && op_token2[i] <= '9')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
