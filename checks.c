#include "monty.h"

/**
 * search_func - function that find the function toi be executed
 * @opcode: Operation code.
 * @cod: Possible value 4 the operation.
 * @n_line: Line number 4 the opcode.
 * @format: Format specifier should be 0 for Stack or 1 for Queue.
 */
void search_func(char *opcode, char *cod, int n_line, int format)
{
	int i;
	int error;

	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", divi},
		{"mul", mult},
		{NULL, NULL}
	};
	if (opcode[0] == '#')
		return;

	for (error = 1, i = 0; functions[i].opcode != NULL; i++)
	{
		if (strcmp(opcode, functions[i].opcode) == 0)
		{
			find_function(functions[i].f, opcode, cod, n_line, format);
			error = 0;
		}
	}
	if (error == 1)
	{
		error_output(3, n_line, opcode);
	}
}

/**
 * find_function - function that find the required function
 * @f: pointer to the function to be called
 * @op_code: pointer to a string representing the opcode
 * @cod: pointer to a string
 * @n_line: line number for the instruction
 * @format: the format specifier
 */
void find_function(op_func f, char *op_code, char *cod, int n_line, int format)
{
	stack_t *node;
	int error;
	int i;

	error = 1;
	if (strcmp(op_code, "push") == 0)
	{
		if (cod != NULL && cod[0] == '-')
		{
			cod = cod + 1;
			error = -1;
		}

		if (cod == NULL)
		{
			error_output(5, n_line);
		}


		for (i = 0; cod[i] != '\0'; i++)
		{
			if (isdigit(cod[i]) == 0)
			{
				error_output(5, n_line);
			}

		}

		node = new_node(atoi(cod) * error);
		if (format == 0)
			f(&node, n_line);
		if (format == 1)
			add_queue(&node, n_line);
	}
	else
		f(&head, n_line);
}
