#include "monty.h"

/**
 * _rotl - Rotates the stack to the top
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _rotl(stack_t **head, unsigned int line_number)
{
stack_t *temp, *last;

(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	temp = *head;
	last = (*head)->next;
	last->prev = NULL;

	while (temp->next)
	{
		temp = temp->next;
	}

	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	*head = last;
}


/**
 * _rotr - Rotates the stack to the bottom
 * @head: Double pointer to the top of the stack
 * @line_number: Line number in the file
 */

void _rotr(stack_t **head, unsigned int line_number)
{
stack_t *temp;

(void)line_number;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}

	temp = *head;

	while (temp->next)
	{
		temp = temp->next;
	}

temp->next = *head;
temp->prev->next = NULL;
temp->prev = NULL;
(*head)->prev = temp;
(*head) = temp;
}
