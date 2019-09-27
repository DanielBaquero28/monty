#include "monty.h"


/**
 * stderr_file_usage - If the user does not give any file or more
 * than one argument
 * to your program.
 * Return: EXIT_FAILURE
**/

void stderr_file_usage(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * stderr_no_instruction - If the file contains an invalid instruction.
 * @line_number: Line number where an error could be found.
 * @op_token: Token where the operation code is found.
 * Return: EXIT_FAILURE
**/

void stderr_no_instruction(char *op_token, unsigned int line_number)
{
	fprintf(stderr, "L<%u>: unknown instruction %s\n",
		line_number, op_token);
	exit(EXIT_FAILURE);
}

/**
 * stderr_failed_malloc - If you can’t malloc anymore.
 * Return: EXIT_FAILURE
**/

void stderr_failed_malloc(void)
{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * stderr_fopen_file - If, for any reason, it’s not possible to open
 * the file.
 * @filename: Name of the file.
 * Return: EXIT_FAILURE
**/

void stderr_fopen_file(char *filename)
{
	fprintf(stderr, "Error: Can't open file <%s>\n", filename);
	exit(EXIT_FAILURE);
}

/**
 * stderr_int_empty - If <int> is not an integer or if there is
 * no argument given to push.
 * @line_number: Line, where an error could have been found.
 * Return: EXIT_FAILURE
**/

void stderr_int_empty(unsigned int line_number)
{
	fprintf(stderr, "L<%u>: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
}
