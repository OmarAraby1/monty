#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @head: pointer to pointer to stack_t
 * @line_num: unused
 * Return: nothing
 */
void _push(stack_t **head, unsigned int line_num)
{
	int n, j = 0, flag = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
			j++;
		for (; bus.arg[j] != '\0'; j++)
		{
			if (bus.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(bus.fi);
			free(bus.line);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	n = atoi(bus.arg);
	if (bus.lifi == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}

/**
 * _pall - prints all the elements of the stack
 * @head: pointer to pointer to stack_t
 * @line_num: number of lines
 * Return: nothing
 */
void _pall(stack_t **head, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)line_num;
	
	if (head == NULL)
	{
		return;
	}
	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * _pint - prints the value at the top
 * @head: head of the stack
 * @line_num: number of lines
 * Return: nothing
 */

void _pint(stack_t **head, unsigned int line_num)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - removes the top element of the stack
 * @head: head of the stack
 * @line_num: number of lines
 * Return: nothing
 */

void _pop(stack_t **head, unsigned int line_num)
{
	stack_t *other;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	other = *head;
	*head = other->next;
	free(other);
}

/**
 * _nop- nothing
 * @head: stack head
 * @line_num: number of lines
 * Return: no return
 */

void _nop(stack_t **head, unsigned int line_num)
{
	(void)line_num;
	(void)head;
}
