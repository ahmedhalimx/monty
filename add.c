#include "monty.h"
/**
 * add - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
 */
void add(stack_t **head, unsigned int counter)
{
	stack_t *h;
	int len = 0, tmp;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = (*head);
	tmp = h->n + h->next->n;
	h->next->n = tmp;
	(*head) = h->next;
	free(h);
}

