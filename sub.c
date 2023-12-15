#include "monty.h"

/**
 * _sub - Subtract the tow top elements in stack
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _sub(stack_t **head, unsigned int line_number)
{
stack_t *curr;

int subb, len = 0;

curr = *head;

	while (curr)
	{
		curr = curr->next;
		len++;
	}

	if (len < 2)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}

	curr = *head;
	subb = curr->next->n - curr->n;
	curr->next->n = subb;
	*head = curr->next;
	free(curr);
}
