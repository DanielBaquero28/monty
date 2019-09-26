#include "monty.h"

char *op_token2 = NULL;

/**
 * main - Entry point of all the program, calls the other functions made.
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: EXIT_FAILURE if an error occurs, or else EXIT_SUCCESS.
**/

int main(int argc, char **argv)
{
	FILE *m_file = NULL;
	int line_number;
	char *line = NULL, *op_token = NULL;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
		stderr_file_usage();
	m_file = fopen(argv[1], "r");
	if (m_file == NULL)
	{
		stderr_fopen_file(argv[1]);
	}
	line_number = 0;
	read = getline(&line, &len, m_file);
	while (read != -1)
	{
		line_number++;
		op_token = strtok(line, " \n\t\a\b");
		op_token2 = strtok(NULL, " \n\t\a\b");
		get_opcode(&stack, op_token, line_number);
		read = getline(&line, &len, m_file);
	}

	free(line);
	free_stack(stack);
	line = NULL;
	fclose(m_file);

	return (EXIT_SUCCESS);
}
