#include "monty.h"

/**
 * _swap - Swaps the top two of stack
 * @head: Pointer to the top of stack
 * @line_number: Line number in the file
 */

void _swap(stack_t **head, unsigned int line_number)
{
int temp;
stack_t *curr;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}

	curr = *head;
	temp = curr->n;
	curr->n = curr->next->n;
	curr->next->n = temp;
}
