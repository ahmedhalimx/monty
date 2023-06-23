#include "monty.h"
/**
 * execute - executes the opcode
 * @content: line content
 * @stack: head linked list - stack
 * @counter: line_counter
 * @monty_file: poiner to monty file
 *
 * Return: 1 on success, EXIT_FAILURE other wise
 */
int execute(char *content, stack_t **stack
		, unsigned int counter, FILE *monty_file)
{
	instruction_t opList[] = {
		{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop},
		{"swap", swap}, {"add", add}, {"nop", nop}, {NULL, NULL}
	};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
		return (0);
	montyData.value = strtok(NULL, " \n\t");
	while (opList[i].opcode && op)
	{
		if (strcmp(op, opList[i].opcode) == 0)
		{
			opList[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (op && opList[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", counter, op);
		fclose(monty_file);
		free(content);
		freeStack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

