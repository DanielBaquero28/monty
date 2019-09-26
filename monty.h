#ifndef HEADER_MONTY_FILE
#define HEADER_MONTY_FILE

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define STACK 1
#define QUEUE 0

extern char *op_token2;


/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
        int n;
        struct stack_s *prev;
        struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/* Main */
int main(int argc, char **argv);


/* Opcode Helper Functions */
stack_t *push_node_empty(stack_t **stack, int n);
stack_t *push_node_full(stack_t **stack, int n);
void free_stack(stack_t **stack);
int *get_opcode(stack_t **stack, char *op_token, unsigned int line_number);

/* Opcode Functions */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

/* Error's Functions */
void stderr_file_usage(void);
void stderr_no_instruction(char *op_token, unsigned int line_number);
void stderr_failed_malloc(void);
void stderr_fopen_file(char *filename);
void stderr_int_empty(unsigned int line_number);

/* Function Helpers */
void token_error(int stat_error);
unsigned int token_length(void);
char *change_to_str(int number);
unsigned int abs_m(int i);
int length_number(unsigned int number, unsigned int help);
void string_buff(unsigned int num, unsigned int help, char *str, int len);
int is_number(void);

/*
int create_stack(stack_t **stack);
int opcode_status(stack_t **stack);
*/

#endif
