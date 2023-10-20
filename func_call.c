#include "monty.h"
/**
 *func_call - The function that perfoms the function calls
 *@f_con : The content read from the file passed
 *@stack : The Stack to be operated on
 *@count : The counter to keep track
 *@f_ptr : The file pointer passed form the file we read from
 */
int func_call(char *f_con, stack_t **stack, unsigned int count, FILE *f_ptr)
{
	instruction_t fun[] = {
	{"push", func_push}, {"pall", func_pall},
	{"pint", func_pint}, {"pop", func_pop},
	{"swap", func_swap}, {"add", func_add},
	{"nop", func_nop}, {"sub", func_sub},
	{"div", func_div}, {"mul", func_mul},
	{"mod", func_mod}, {"pchar", func_pchar},
	{"pstr", func_pstr}, {"rotl", func_rotl},
	{"rotr", func_rotr}, {"queue", func_queue},
	{"stack", func_stack}, {NULL, NULL}
	};
	char *operation;
	unsigned int i = 0;

	operation = strtok(f_con, "\n\t");
	if (operation && operation[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (fun[i].opcode && operation)
	{
		if (strcmp(operation, fun[i].opcode) == 0)
		{
			fun[i].f(stack, count);
			return (0);
		}
		i++;
	}
	if (operation && fun[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", count, operation);
		fclose(f_ptr);
		free(f_con);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
