#include "monty.h"

/**
 * add - adds the top two elements of the stack
 * Function adds the value of the first and second node of doubly linked list
 * and stores the results in the second node
 * @stack: pointer to the top of the stack
 * @num: line number of the opcode
*/
void add(stack_t **stack, unsigned int num)
{
	int rslt;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		error_output2(9, num, "add");

	(*stack) = (*stack)->next;
	rslt = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = rslt;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - does nothing
 * Function does nothing. It casts stack and num to void to avoid
 * unused variable warnings
 * @stack: pointer to the top of the stack
 * @num: line number of the opcode
*/
void nop(stack_t **stack, unsigned int num)
{
	(void)*stack;
	(void)num;
}

