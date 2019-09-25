#include "monty.h"

char *op_token = NULL;
char *op_token2 = NULL;

/**
 * main - Entry point of all the program, calls the other functions made.
 * @argc: Argument Count
 * @argv: Argument Vector
 * Return: EXIT_FAILURE if an error occurs, or else EXIT_SUCCESS.
**/

int main(int argc, char **argv)
{
	FILE *m_file;
	int line_number;
	char *line = NULL;
	stack_t *stack = NULL;
	size_t len = 0;
	ssize_t read;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	m_file = fopen(argv[1], "r");
	if (!m_file)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 1;
	while ((read = getline(&line, &len, m_file)) != -1)
	{
		op_token = strtok(line, " \n\t\a\r\b");
		op_token2 = strtok(NULL, " \n\t\a\r\b");
		get_opcode(&stack, op_token, line_number);
		line_number++;
	}

	free(line);
	line = NULL;
	fclose(m_file);

	return (EXIT_SUCCESS);
}
