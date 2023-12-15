#include "monty.h"

/**
 * reader - Reads content from a file
 * @file: Pointer to the file to be read
 */

void reader(FILE *file)
{
	size_t size = 0;
	char *content = NULL;
	unsigned int line_number = 1;

	while (getline(&content, &size, file) != -1)
	{
		carrier_s.content = content;
		parser(carrier_s.content, line_number);
		line_number++;
	}

	free(content);
}

/**
 * parser - Tokenize a command
 * @content: Command string to be tokenized
 * @line_number: number of line in file
 */

void parser(char *content, unsigned int line_number)
{
char *token;

	token = strtok(content, " \n\t$");

	if (token == NULL || token[0] == '#')
		return;
	
	carrier_s.arg = strtok(NULL, " \n\t$");

	executor(token, line_number);
}

/**
 * executor - Executes command
 * @command: Tokenized command to be executed
 * @line_number: number of line in file
 */

void executor(char *command, unsigned int line_number)
{
	int i;

	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"nop", _nop},
		{NULL, NULL}
	};

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(command, instructions[i].opcode) == 0)
		{
			instructions[i].f(&(carrier_s.head), line_number);
			return;
		}
	}

	fprintf(stderr, "Unknown instruction: %s\n", command);
	fclose(carrier_s.file);
	free(carrier_s.content);
	exit(EXIT_FAILURE);

}


/**
 * free_stack - Frees memory allocated for a stack
 * @head: Pointer to the top of the stack
 */

void free_stack(stack_t *head)
{
stack_t *temp;

temp = head;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

