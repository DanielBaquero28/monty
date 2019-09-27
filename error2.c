#include "monty.h"

/**
 * stderr_pint - Can't pint.
 * @line_number: Line number where error occured.
 * Nothing: Nothing.
**/

void stderr_pint(unsigned int line_number)
{
	char *string;

	fprintf(stderr, "L<%d>: can't pint, stack empty\n", line_number);
	string = change_to_str(line_number);
	free(string);
	exit(EXIT_FAILURE);
}

/**
 * stderr_pop - Can't pop, stack empty.
 * @line_number: Line number where an error was occured.
 * Return: EXIT_FAILURE.
**/

void stderr_pop(unsigned int line_number)
{
	char *string;

	fprintf(stderr, "L<%u>: can't pop an empty stack\n", line_number);
	string = change_to_str(line_number);
	free(string);
	exit(EXIT_FAILURE);
}

/**
 * stderr_op - Shows opcode error depending on what the error was..
 * @line_number: Line number where an error was occured.
 * @op: Operation code where an error occurred.
 * Return: EXIT_FAILURE
**/

void stderr_op(unsigned int line_number, char *op)
{
	char *string;

	fprintf(stderr, "L<%u>: can't %s, stack too short\n",
		line_number, op);
	string = change_to_str(line_number);
	free(string);
	exit(EXIT_FAILURE);
}
