#include "monty.h"
bus_t bus = {NULL, NULL, NULL, 0};
/**
 * free_stack - frees a doubly linked list
 * @head: head of the stack
 */
void free_stack(stack_t *head)
{
	stack_t *aux;

	aux = head;
	while (head)
	{
		aux = head->next;
		free(head);
		head = aux;
	}
}
/**
 * exec_monty - executes the opcode
 * @stack: head linked list - stack
 * @line_num: number of line
 * @fi: poiner to monty file
 * @line: line content
 * Return: nothing
 */
int exec_monty(char *line, stack_t **stack, unsigned int line_num, FILE *fi)
{
	instruction_t opst[] = {{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {"sub", _sub},
		{"div", _div}, {"mul", _mul}, {"mod", _mod},
		{"pchar", _pchar}, {"pstr", _pstr}, {"rotl", _rotl},
		{"rotr", _rotr}, {"stack", _stack}, {"queue", _queue},
		{NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(line, DELIMS);
	if (op && op[0] == '#')
		return (0);
	bus.arg = strtok(NULL, DELIMS);
	while (opst[i].opcode && op)
	{
		if (strcmp(op, opst[i].opcode) == 0)
		{	opst[i].f(stack, line_num);
			return (0);
		}
		i++;
	}
	if (op && opst[i].opcode == NULL)
	{fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
		fclose(fi);
		free(line);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
/**
 * main - monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	char *line;
	FILE *fi;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fi = fopen(argv[1], "r");
	bus.fi = fi;
	if (!fi)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		line = NULL;
		read_line = getline(&line, &size, fi);
		bus.line = line;
		line_num++;
		if (read_line > 0)
		{
			exec_monty(line, &stack, line_num, fi);
		}
		free(line);
	}
	free_stack(stack);
	fclose(fi);
	return (0);
}
