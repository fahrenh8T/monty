#include "monty.h"

/**
 * push - pushes an element to the stack
 * Function adds a new node at the beginning of a doubly linked list
 * @stack: a pointer to the new node to be added
 * @num: line number of the opcode
*/
void push(stack_t **stack, unsigned int num)
{
	stack_t *nnode, *temp;
	(void) num;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);

	nnode = *stack;

	if (head == NULL)
	{
		head = nnode;
		return;
	}

	temp = head;
	temp->prev = NULL;
	head = nnode;
	head->next = temp;
	temp->prev = head;
}

/**
 * pall - prints all the values on the stack
 * Function prints all integers stored in a doubly linked list
 * @stack: a pointer to the top of the stack
 * @num: line number of the opcode
*/
void pall(stack_t **stack, unsigned int num)
{
	stack_t *crrnt;
	(void) num;

	if (stack == NULL)
		exit(EXIT_FAILURE);

	crrnt = *stack;

	while (crrnt != NULL)
	{
		fprintf(stdout, "%d\n", crrnt->n);
		crrnt = crrnt->next;
	}
}

/**
 * pint - prints the value at the top of the stack
 * Function prints the integer stored in the first node of doubly linked list
 * @stack: pointer to the top of the stack
 * @num: line number of the opcode
*/
void pint(stack_t **stack, unsigned int num)
{
	if (stack == NULL || *stack == NULL)
		error_output2(6, num);

	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * Function deletes the first node of doubly linked list and frees its memory
 * @stack: pointer to the top of stack
 * @num: line number of the opcode
*/
void pop(stack_t **stack, unsigned int num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		error_output2(7, num);

	temp = *stack;
	*stack = temp->next;

	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * swap - swaps top two elements of stack
 * Function swaps the value of the first and second values of
 * the first and second values of doubly linked list
 * @stack: pointer to the top of the stack
 * @num: line number of the opcode
*/
void swap(stack_t **stack, unsigned int num)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_output2(8, num, "swap");

	temp = (*stack)->next;
	(*stack)->next = temp->next;

	if (temp->next != NULL)
		temp->next->prev = *stack;

	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}
