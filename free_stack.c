#include "monty.h"
/**
 *free_stack - Clears The Lists
 *@head: The head pointer of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
