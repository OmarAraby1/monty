#include "monty.h"
/**
 * _push - pushes an element to the stack
 * @head: pointer to pointer to stack_t
 * @val: value to push
 * @line_num: unused
 * Return: nothing
 */
void _push(stack_t **head, int val, unsigned int line_num)
{
	stack_t *new_node;
	(void)line_num;

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
 * @val: unused
 * @line_num: number of lines
 * Return: nothing
 */
void _pall(stack_t **head, int val, unsigned int line_num)
{
	stack_t *temp = *head;
	(void)val;
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
 * @val: unused
 * @line_num: number of lines
 * Return: nothing
 */

void _pint(stack_t **head, int val, unsigned int line_num)
{
	(void)val;

	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
/**
 * _pop - removes the top element of the stack
 * @head: head of the stack
 * @val: unused
 * @line_num: number of lines
 * Return: nothing
 */

void _pop(stack_t **head, int val, unsigned int line_num)
{
	stack_t *other;
	(void)val;

	if (*head == NULL || head == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_num);
		exit(EXIT_FAILURE);
	}
	other = *head;
	*head = other->next;
	free(other);
}
/**
 * _nop- nothing
 * @head: stack head
 * @val: unused
 * @line_num: number of lines
 * Return: no return
 */
void _nop(stack_t **head, int val, unsigned int line_num)
{
	(void)line_num;
	(void)head;
	(void)val;
}
