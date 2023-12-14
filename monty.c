#include "monty.h"

carrier_t carrier_s = {0, NULL, NULL, NULL, NULL};

/**
 * main - Entry point to the Monty interpreter
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: EXIT_SUCCESS (Success), EXIT_FAILURE otherwise
 */

int main(int argc, char *argv[])
{

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	carrier_s.file = fopen(argv[1], "r");

	if (!carrier_s.file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	reader(carrier_s.file);
	free_stack(carrier_s.head);
	fclose(carrier_s.file);
	return (EXIT_SUCCESS);
}
