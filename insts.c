#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @head: pointer to pointer to stack_t
 * @val: value to push
 * Return: nothing
 */
void _push(stack_t **head, int val)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = val;
	new_node->prev = NULL;
	new_node->next = *head;
	if (*head != NULL)
	{
		(*head)->prev = new_node;
	}
	*head = new_node;
}
/**
 * _pall - prints all the elements of the stack
 * @head: pointer to pointer to stack_t
 * @val: unused here
 * Return: nothing
 */
void _pall(stack_t **head, int val)
{
	stack_t *temp = *head;
	(void)val;

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
 * @cline: number of lines
 * Return: nothing
 */

void _pint(stack_t **head, unsigned int cline)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", cline);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
