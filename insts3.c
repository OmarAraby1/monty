#include "monty.h"
/**
 * _mod - modulus of the top two elements of the stack
 * @head: stack head
 * @line_num: number of line
 * Return: nothing
*/
void _mod(stack_t **head, unsigned int line_num)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_num);
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
	aux = h->next->n % h->n;
	h->next->n = aux;
	*head = h->next;
	free(h);
}
/**
 * _pchar - prints the char at the top of the stack
 * @head: stack head
 * @line_num: number of line
 * Return: nothing
*/
void _pchar(stack_t **head, unsigned int line_num)
{
	stack_t *h;

	h = *head;
	if (!h)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (h->n > 127 || h->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
		fclose(bus.fi);
		free(bus.line);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", h->n);
	free(h);
}
/**
 * _pstr - prints the string starting at the top of the stack
 * @head: stack head
 * @line_num: unused
 * Return: nothing
*/
void _pstr(stack_t **head, unsigned int line_num)
{
	stack_t *h;
	(void)line_num;

	h = *head;
	while (h)
	{
		if (h->n > 127 || h->n <= 0)
		{
			break;
		}
		printf("%c", h->n);
		h = h->next;
	}
	printf("\n");
	free(h);
}
/**
 * _rotl - rotates the stack to the top
 * @head: stack head
 * @line_num: unused
 * Return: nothing
 */
void _rotl(stack_t **head, unsigned int line_num)
{
	stack_t *tmp = *head, *aux;
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
	free(aux);
	free(temp);
}
/**
 * _rotr - rotates the stack to the bottom
 * @head: the stack head
 * @line_num: unused
 * Return: nothing
 */
void _rotr(stack_t **head, unsigned int line_num)
{
	stack_t *copy;
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
	free(copy);
}
