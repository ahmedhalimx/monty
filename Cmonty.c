#include "monty.h"
montyInput_t montyData = {NULL, NULL, NULL};
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	FILE *monty_file;
	char *content = NULL;
	size_t size = 0, counter = 0, read_line = 1;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	montyData.file = monty_file;
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0 || (!feof(monty_file)))
	{
		read_line = getline(&content, &size, monty_file);
		montyData.content = content;
		counter++;
		if (read_line != 0)
		{
			execute(content, &stack, counter, monty_file);
		}
		free(content);
	}
	freeStack(stack);
	fclose(monty_file);
	return (0);
}

