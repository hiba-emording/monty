#include "monty.h"

/**
 * _pop - Removes the top in stack
 * @head: Pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _pop(stack_t **head, unsigned int line_number)
{
stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}

	temp = *head;
	*head = (*head)->next;
	free(temp);
}
