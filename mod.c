#include "monty.h"

/**
 * _mod - Calculates the rest of division of 2 top elements in stack
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _mod(stack_t **head, unsigned int line_number)
{
stack_t *curr;

int total, len = 0;

curr = *head;

	while (curr)
	{
		curr = curr->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}
	curr = *head;
	if (curr->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}
	total = curr->next->n % curr->n;
	curr->next->n = total;
	*head = curr->next;
	free(curr);
}
