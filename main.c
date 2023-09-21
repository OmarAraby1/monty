#include "monty.h"
/**
*stack_init - initialize stack
*@head: pointer to pointer to stack_t
*Return: void
*/
void stack_init(stack_t **head)
{
	*head = NULL;
}
/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	instruction_t insts[] = {{"push", _push}, {"pall", _pall},
		{"pint", _pint}, {"pop", _pop}, {"swap", _swap},
		{"add", _add}, {"nop", _nop}, {"sub", _sub}, {"div", _div},
		{"mul", _mul}, {"mod", _mod}, {"pchar", _pchar},
		{"rotl", _rotl}, {"rotr", _rotr}, {NULL, NULL}};
	ssize_t read;
	size_t size = 0;
	FILE *fi = NULL;
	char *op = NULL, *sval = NULL, *line = NULL;
	unsigned int i = 0, line_num = 0;
	int val;
	stack_t *head;

	stack_init(&head);
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		if (!argv[1])
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			exit(EXIT_FAILURE);
		}
		fi = fopen(argv[1], "r");
		if (fi == NULL)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[i]);
			fclose(fi);
			exit(EXIT_FAILURE);
		}
		while ((read = getline(&line, &size, fi)) != -1)
		{
			op = strtok(line, DELIMS);
			if (op[0] == '#')
			{
				continue;
			}
			line_num++;
			if (op)
			{
				i = 0;
				while (insts[i].opcode != NULL)
				{
					if (strcmp(op, insts[i].opcode) == 0)
					{
						sval = strtok(NULL, DELIMS);
						if (strcmp(op, "push") == 0)
						{
							if (sval == NULL)
							{
								fclose(fi);
								fprintf(stderr, "Line %d: usage: push integer\n", line_num);
								exit(EXIT_FAILURE);
							}
							else
							{
								val = atoi(sval);
							}
						}
						insts[i].f(&head, val, line_num);
						break;
					}
					i++;
				}
				if (insts[i].opcode == NULL)
				{
					fclose(fi);
					fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
					exit(EXIT_FAILURE);
				}
			}
		}
		fclose(fi);
		exit(EXIT_SUCCESS);
	}
}
