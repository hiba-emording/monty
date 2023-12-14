#include "monty.h"

/**
 * reader - Reads content from a file
 * @file: Pointer to the file to be read
 */

void reader(FILE *file)
{
char *content = NULL;
size_t size = 0;
ssize_t read_line = 1;
unsigned int line_number = 0;

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		carrier_s.content = content;
		line_number++;

		if (read_line > 0)
		{
			parser(content, line_number);
		}
		free(content);
	}
}

/**
 * parser - Tokenize a command
 * @content: Command string to be tokenized
 */

void parser(char *content, unsigned int line_number)
{
char *token;

	token = strtok(content, " \n\t$");

	if (token == NULL)
	{
		return;
	}

	carrier_s.arg = strtok(NULL, " \n\t$");

	/* TEST */
	printf("Command: %s\n", token);
	printf("Argument: %s\n", carrier_s.arg);

	executor(token, line_number);
}

/**
 * executor - Executes command
 * @command: Tokenized command to be executed
 */

void executor(char *command, unsigned int line_number)
{
int i;
stack_t *arg_stack = (stack_t *)carrier_s.arg;
stack_t *temp;

instruction_t instructions[] = {
	{"push", _push},
	{"pall", _pall},
	{"pint", _pint},
	{"nop", _nop},
	{NULL, NULL}
};

/* Test */

printf("Line Number: %u\n", line_number);

temp = arg_stack;
printf("Argument Stack: ");
while (temp != NULL)
{
printf("%d ", temp->n);
temp = temp->next;
}
printf("\n");

	for (i = 0; instructions[i].opcode != NULL; i++)
	{
		if (strcmp(command, instructions[i].opcode) == 0)
		{
			instructions[i].f(&arg_stack, line_number);
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

