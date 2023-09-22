#include "monty.h"
/**
 * _swap - adds the top two elements of the stack.
 * @head: stack head
 * @line_num: number of line
 * Return: no return
*/
void _swap(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n;
	h->n = h->next->n;
	h->next->n = aux;
}
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @line_num: number of line
 * Return: no return
*/
void _add(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->n + h->next->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
 * _sub - sustract top two numbers of the stack
 * @head: stack head
 * @line_num: number of line
 * Return: no return
 */
void _sub(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n - h->n;
	h->next->n = aux;
	*head = h->next;
}
/**
 * _div - divides top two numbers of the stack
 * @head: stack head
 * @line_num: number of line
 * Return: nothing
 */
void _div(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	if (h->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	else
	{
		aux = h->next->n / h->n;
		h->next->n = aux;
		*head = h->next;
	}
}
/**
 * _mul - multiplies the top two elements of the stack
 * @head: stack head
 * @line_num: number of line
 * Return: nothing
*/
void _mul(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	int len = 0, aux;

	h = *head;
	while (h)
	{
		h = h->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	aux = h->next->n * h->n;
	h->next->n = aux;
	*head = h->next;
}
