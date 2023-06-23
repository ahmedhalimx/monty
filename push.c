#include "monty.h"

/**
 * push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */

void push(stack_t **head, unsigned int counter)
{
	int n, i = 0, fail_flag = 0;

	if (montyData.value)
	{
		if (montyData.value[0] == '-')
			i++;
		for (; montyData.value[i] != '\0'; i++)
		{
			if (montyData.value[i] > 57 || montyData.value[i] < 48)
				fail_flag = 1;
		}
		if (fail_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(montyData.file);
			free(montyData.content);
			freeStack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	n = atoi(montyData.value);
	addnode(head, n);
}

