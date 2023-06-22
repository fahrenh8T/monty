#include "monty.h"
/**
 * new_node - Function that creates a new node
 * @n: integer
 * Return: pointer to a node
 */
stack_t *new_node(int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		error_output(4);
	new->next = NULL;
	new->prev = NULL;
	new->n = n;
	return (new);
}
/**
 * free_node - function that frees a linked list
 */
void free_node(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
