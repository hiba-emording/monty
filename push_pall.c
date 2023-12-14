#include "monty.h"

/**
 * add_node - Adds a new node to the head of stack
 * @head: Pointer to the head of the stack
 * @value: Value to be stored in the new node
 */

void add_node(stack_t **head, int value)
{
	stack_t *new, *curr;

	curr = *head;

	new = malloc(sizeof(stack_t));

	if (new == NULL)
	{
		fprintf(stderr, "Error: Unable to allocate memory for a new node\n");
		exit(EXIT_FAILURE);
	}

	if (curr != NULL)
	{
		curr->prev = new;
	}

	new->n = value;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}

/**
 * _push - Pushes a value to stack
 * @head: Pointer to the head of stack
 * @line_number: Line number in the file
 */

void _push(stack_t **head, unsigned int line_number)
{
	int value, i = 0;
	char *arg = carrier_s.arg;

	if (arg != NULL)
	{
		for (; arg[i] != '\0'; i++)
		{
			if (isdigit(arg[i]) || arg[i] == '-')
			{
				continue;
			}
			else
			{
				fprintf(stderr, "L%d: usage: push integer\n", line_number);
				fclose(carrier_s.file);
				free(carrier_s.content);
				exit(EXIT_FAILURE);
			}

		}
	}

	value = atoi(arg);
	add_node(head, value);
}


/**
 * _pall - Prints all values in the stack
 * @head: Pointer to the head of stack
 * @line_number: Line number (empty)
 */

void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *curr;
	(void)line_number;

	curr = *head;

	if (curr == NULL)
	{
		return;
	}

	while (curr != NULL)
	{
		printf("%d\n", curr->n);
		curr = curr->next;
	}
}

