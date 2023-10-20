#include "monty.h"
/**
 *main -Start of the program execution
 *@argv: Argument Vector
 *@argc: Argumect Counter
 *Return: Always 0 after success
 */
int main(int argc, char *argv[])
{
FILE *file_ptr;

if (argc != 2)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
file_ptr = fopen(argv[1], "r");
if (!file_ptr)
{
	fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
	exit(EXIT_FAILURE);
}

return (0);
}
