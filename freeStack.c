#include "monty.h"
/**
 * freeStack - frees a doubly linked list
 * @head: head of the stack
 */
void freeStack(stack_t *head)
{
	stack_t *tmp;

	tmp = head;
	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

