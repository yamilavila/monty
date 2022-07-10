#ifndef _MONTY_H_
#define _MONTY_H_

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct build - instance of monty interpreter
 * @fd: file stream for file being read
 * @bufer: holds the current line being precess
 * @stack: the stack
 * @mode: keep track of a stack(1) or queue(0)
 * @token: bytecodes read from the line
 */


typedef struct build
{
	FILE *fd;
	int mode;
	stack_t *stack;
	char *buf;
	char **token;
} build_t;

extern build_t b;

void push(stack_t **, unsigned int);
void pall(stack_t **, unsigned int);
void pint(stack_t **, unsigned int);
void pop(stack_t **, unsigned int);
void swap(stack_t **, unsigned int);
void add(stack_t **, unsigned int);
void nop(stack_t **, unsigned int);
void sub(stack_t **, unsigned int);
void _div(stack_t **, unsigned int);
void mul(stack_t **, unsigned int);
void mod(stack_t **, unsigned int);
void pstr(stack_t **, unsigned int);
void pchar(stack_t **, unsigned int);
void rotl(stack_t **, unsigned int);
void rotr(stack_t **, unsigned int);
void stack(stack_t **, unsigned int);
void queue(stack_t **, unsigned int);

void (*get_inst(char *))(stack_t **, unsigned int);

void validate_args(int, char**);




#endif


