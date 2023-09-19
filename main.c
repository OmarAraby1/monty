#include "monty.h"
/**
 * main - entry point
 * @argc: argument count
 * @argv: array of arguments
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(int argc, char **argv)
{
	stack_t *head = NULL;
	instruction_t insts[] = {
		{"push", _push},
		{"pall", _pall},
		{NULL, NULL}};
	FILE *fi;
	int len = 0;
	char *stk, *tok, *line = NULL;
	unsigned int i = 0, line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fi = fopen(argv[1], "r");
	if (fi == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[i]);
		exit(EXIT_FAILURE);
	}
	while (fgets(line, len, fi) != NULL)
	{
		stk = strtok(line, DELIMS);
		line_num++;
		if (stk)
		{
			tok = strtok(line, " \n");
			while (insts[i].opcode != NULL)
			{
				if (strcmp(tok, insts[i].opcode) == 0)
				{
					insts[i].f(&head, line_num);
					break;
				}
				i++;
			}
			if (insts[i].opcode == NULL)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_num, tok);
			}
		}
	}
	free(line);
	fclose(fi);
	exit(EXIT_SUCCESS);
}
