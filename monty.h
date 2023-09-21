#ifndef MONTY_H
#define MONTY_H
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <limits.h>
#include <ctype.h>

#define DELIMS "\n \t\r"

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
	void (*f)(stack_t **stack, int val, unsigned int line_num);
} instruction_t;

int main(int argc, char **argv);
void _push(stack_t **head, int val, unsigned int line_num);
void _pall(stack_t **head, int val, unsigned int line_num);
void _pint(stack_t **head, int val, unsigned int line_num);
void _pop(stack_t **head, int val, unsigned int line_num);
void _swap(stack_t **head, int val, unsigned int line_num);
void _add(stack_t **head, int val, unsigned int line_num);
void _nop(stack_t **head, int val, unsigned int line_num);
void _sub(stack_t **head, int val, unsigned int line_num);
void _div(stack_t **head, int val, unsigned int line_num);
void _mul(stack_t **head, int val, unsigned int line_num);
void _mod(stack_t **head, int val, unsigned int line_num);
void _pchar(stack_t **head, int val, unsigned int line_num);
void _rotl(stack_t **head, int val, unsigned int line_num);
void _rotr(stack_t **head, int val, unsigned int line_num);
void _pstr(stack_t **head, int val, unsigned int line_num);

#endif
