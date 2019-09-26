#include "monty.h"

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
