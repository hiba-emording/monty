#include "monty.h"

/**
 * _stack - Sets format to (LIFO)
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	carrier_s.isQueue = 0;
}


/**
 * _queue - Sets format to (FIFO)
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	carrier_s.isQueue = 1;
}
