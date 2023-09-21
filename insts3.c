#include "monty.h"
/**
 * _mod - modulus of the top two elements of the stack
 * @head: stack head
 * @val: unused
 * @line_num: number of line
 * Return: nothing
*/
void _mod(stack_t **head, int val, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;
	(void)val;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		exit(EXIT_FAILURE);
	}
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
}
/**
 * _pchar - prints the char at the top of the stack
 * @head: stack head
 * @val: unused
 * @line_num: number of line
 * Return: nothing
*/
void _pchar(stack_t **head, int val, unsigned int line_num)
{
	stack_t *h;
	(void)val;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
}
/**
 * _rotl - rotates the stack to the top
 * @head: stack head
 * @val: unused
 * @line_num: unused
 * Return: nothing
 */
void _rotl(stack_t **head, int val, unsigned int line_num)
{
	stack_t *tmp = *head, *aux;
	(void)val;
	(void)line_num;

	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	aux = (*head)->next;
	aux->prev = NULL;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux;
}
/**
 * _rotr - rotates the stack to the bottom
 * @head: stack head
 * @val: unused
 * @line_num: unused
 * Return: nothing
 */
void _rotr(stack_t **head, int val, unsigned int line_num)
{
	stack_t *copy;
	(void)val;
	(void)line_num;

	copy = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (copy->next)
	{
		copy = copy->next;
	}
	copy->next = *head;
	copy->prev->next = NULL;
	copy->prev = NULL;
	(*head)->prev = copy;
	(*head) = copy;
}
