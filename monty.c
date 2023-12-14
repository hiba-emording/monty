#include "monty.h"

carrier_t carrier_s = {NULL, NULL, NULL, 0};

/**
 * main - Entry point to the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS (Success), EXIT_FAILURE otherwise
 */

int main(int argc, char *argv[])
{
FILE *file;
stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	carrier_s.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	reader(file);
	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}
