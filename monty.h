#ifndef HEADER_MONTY_FILE
#define HEADER_MONTY_FILE

/* Libraries */
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <errno.h>

/* Opcode and argument tokens */
extern char *op_token;
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

/* Opcode Functions */
void op_push(stack_t **stack, unsigned int line_number);
void op_pall(stack_t **stack, unsigned int line_number);

/* Opcode Helper Functions */
void *get_opcode(stack_t **stack, char *op_token, unsigned int line_number);
#endif
