#include "monty.h"
/**
 *sub- substract two top elem
 *@head: stack head
 *@counter: line_number
 *Return: no return
 */

void sub(stack_t **head, unsigned int counter)
{
	stack_t *h = *head;
	int node_ptr, nodes;

	for (nodes = 0; h != NULL; nodes++)
		h = h->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(montyData.file);
		free(montyData.content);
		freeStack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	node_ptr = h->next->n - h->n;
	h->next->n = node_ptr;
	*head = h->next;
	free(h);
}
