#include "monty.h"

/**
 * is_number - Checks if it's a number or not.
 * @op_token: Token to be reviewed if it's a number or not.
 * Return: 1 is True or 0 if false.
 **/

int is_number(char *op_token)
{
	int i;

	i = 0;
	while (op_token)
	{
		if (token[i] >= '0' && token[i] <= '9')
			return (1);
		else
			return (0);
		i++;
	}
	return (0);
}
