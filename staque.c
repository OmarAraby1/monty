#include "monty.h"
/**
 * addnode - add node to the head stack
 * @head: head of the stack
 * @n: new value to add
 * Return: nothing
*/
void addnode(stack_t **head, int n)
{

	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux)
		aux->prev = new_node;
	new_node->n = n;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}
/**
 * addqueue - add node to the tail stack
 * @n: new value to add
 * @head: head of the stack
 * Return: nothing
*/
void addqueue(stack_t **head, int n)
{
	stack_t *new_node, *aux;

	aux = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error\n");
	}
	new_node->n = n;
	new_node->next = NULL;
	if (aux)
	{
		while (aux->next)
			aux = aux->next;
	}
	if (!aux)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		aux->next = new_node;
		new_node->prev = aux;
	}
}
/**
 * _stack - use stack data structure
 * @head: stack head
 * @line_num: number of line
 * Return: nothing
*/
void _stack(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	bus.lifi = 0;
}
/**
 * _queue - use queue data structure
 * @head: stack head
 * @line_num: number of line
 * Return: nothing
*/
void _queue(stack_t **head, unsigned int line_num)
{
	(void)head;
	(void)line_num;
	bus.lifi = 1;
}
