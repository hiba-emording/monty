#include "monty.h"


/**
 * _mul - Multiplies the top two elements of the stack
 * @head: Pointer to the head of the stack
 * @line_number: Line number in file
 */

void _mul(stack_t **head, unsigned int line_number)
{
stack_t *curr;
int len = 0, total;

curr = *head;

	while (curr)
	{
		curr = curr->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}

	curr = *head;
	total = curr->n * curr->next->n;
	curr->next->n = total;
	*head = curr->next;
	free(curr);
}
