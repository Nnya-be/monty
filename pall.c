#include "monty.h"
/**
 *func_pall - prints data in the stack
 *@head: Head pointer to the stack
 *@counter: has to be passed
 *Return : Nothing to Return
 */
void func_pall(stack_t **head, unsigned int counter)
{
stack_t *temp;

	temp = *head;
	if (temp == NULL)
	{
		return;
	}
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
	(void)counter;
}
