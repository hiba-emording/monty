#include "monty.h"

/**
 * _pchar - Prints the character at the top of the stack
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = *head;
	if (temp == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}
	if (temp->n < 0 || temp->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n", line_number);
		fclose(carrier_s.file);
		free(carrier_s.content);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp->n);
}


/**
 * _pstr - Prints the string starting at the top of the stack
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _pstr(stack_t **head, unsigned int line_number)
{
stack_t *temp;
(void)line_number;

temp = *head;

	while (temp != NULL && temp->n != 0 && (temp->n >= 0 && temp->n <= 127))
	{
		if (temp->n == 0)
		{
			break;
		}

		printf("%c", temp->n);
		temp = temp->next;
	}

	printf("\n");
}
