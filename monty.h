#ifndef MONTY_H_
#define MONTY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <ctype.h>
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#endif

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;
int func_call(char *file_content, stack_t **stack, unsigned int counter , FILE *file_ptr);
void free_stack(stack_t *head);
void func_pall(stack_t **head, unsigned int counter);
void func_queue(stack_t **head, unsigned  int counter);
void addqueue(stack_t **head, int n);
void func_push(stack_t **head, unsigned int counter);
void addnode(stack_t **head, int n);
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void func_pint(stack_t **head, unsigned int number);
void func_pop(stack_t **head, unsigned int counter);
void func_swap(stack_t **head, unsigned int counter);
void func_add(stack_t **head, unsigned int counter);
void func_nop(stack_t **head, unsigned int counter);
void func_sub(stack_t **head, unsigned int counter);
void func_div(stack_t **head, unsigned int counter);
void func_mul(stack_t **head, unsigned int counter);
void func_mod(stack_t **head, unsigned int counter);
void func_pchar(stack_t **head, unsigned int counter);
void func_pstr(stack_t **head, unsigned int counter);
void func_rotl(stack_t **head, unsigned int counter);
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void func_stack(stack_t **head, unsigned int counter);
