#include "monty.h"
/**
 *main -Start of the program execution
 *@argv: Argument Vector
 *@argc: Argumect Counter
 *Return: Always 0 after success
 */
bus_t bus = {NULL, NULL, NULL, 0};
int main(int argc, char *argv[])
{
FILE *file_ptr;
size_t size_read = 0;
ssize_t line_read;
char *file_content = NULL;
unsigned int counter = 0;
stack_t *stack = NULL;

if (argc != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
file_ptr = fopen(argv[1], "r");
bus.file = file_ptr;
if (!file_ptr)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}
while (line_read > 0)
{
	file_content = NULL;
	line_read = getline (&file_content, &size_read, file_ptr);
	bus.content = file_content;

	if (line_read > 0)
	{
		func_call(file_content, &stack, counter, file_ptr);
	}
	free(file_content);
}
free_stack(stack);
fclose(file_ptr);
return (0);
}
