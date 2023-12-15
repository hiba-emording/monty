#ifndef MONTY_H
#define MONTY_H

#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>


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
 * struct carrier_s - structure for holding carrier data
 * @arg: pointer representing a value
 * @file: pointer for file handling
 * @content: pointer representing command strings
 * @isQueue: int flag indicating queue mode (1) or non-queue mode (0)
 * @head: head of stack
 */

typedef struct carrier_s
{
	int isQueue;
	char *content;
	char *arg;
	FILE *file;
	stack_t *head;
} carrier_t;

/* GLOBAL VAR */

extern carrier_t carrier_s;

/* MAIN FUNCTIONS */

void reader(FILE *file);
void parser(char *content, unsigned int line_number);
void executor(char *command, unsigned int line_number);
void free_stack(stack_t *head);

/* PROTYPES */

void _push(stack_t **stack, unsigned int line_number);
void _pall(stack_t **stack, unsigned int line_number);
void _pint(stack_t **head, unsigned int line_number);
void _pop(stack_t **head, unsigned int line_number);
void _swap(stack_t **head, unsigned int line_number);
void _add(stack_t **head, unsigned int line_number);
void _nop(stack_t **head, unsigned int line_number);

void _sub(stack_t **head, unsigned int line_number);
void _mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void _mod(stack_t **head, unsigned int line_number);

void _pchar(stack_t **head, unsigned int line_number);
void _pstr(stack_t **head, unsigned int line_number);

void _rotl(stack_t **head, unsigned int line_number);
void _rotr(stack_t **head, unsigned int line_number);

void _stack(stack_t **head, unsigned int line_number);
void _queue(stack_t **head, unsigned int line_number);

/* HELPER FUNCTIONS */

void add_node(stack_t **head, int value);
void add_node_t(stack_t **head, int value);

#endif
