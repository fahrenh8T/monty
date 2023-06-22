#include "monty.h"

/**
 * sub - subtracts the top element of the stack from the second top element
 * Fucntion subtracts the value of the first node from the value of the
 * second value of doubly linked list and stores the result in the seond node
 * @stack: pointer to the top of the stack
 * @num: line number of the opcode
*/
void sub(stack_t **stack, unsigned int num)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_output2(8, num, "sub");

	(*stack) = (*stack)->next;
	rslt = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * div - divides the second top element of the stack by the top element
 * Fucntion divides the value of the second node by the value of the first
 * and store result in second node
 * @stack: pointer to the top of the stack
 * @num: line number of the opcode
*/
void divd(stack_t **stack, unsigned int num)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_output2(8, num, "divd");

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", num);
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->next;
	rslt = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - multiples the second top element of the stack with the top element
 * @stack: pointer of the top of the stack
 * @num: line number of the opcode
*/
void mult(stack_t **stack, unsigned int num)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_output2(8, num, "mult");

	(*stack) = (*stack)->next;
	rslt = (*stack)->n * (*stack)->prev->n;
	free((*stack)->prev);
	(*stack)->prev = NULL;
	(*stack)->n = rslt;
}

/**
 * add_queue - adds a node to the end of the queue
 * Function adds a node to the end of doubly linked list
 * @stack: pointer to the node to be added
 * @num: line number of the opcode
 */
void add_queue(stack_t **stack, unsigned int num)
{
	stack_t *temp;
	(void) num;

	if (stack == NULL || *stack == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *stack;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
}
