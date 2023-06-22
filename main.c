#include "monty.h"
stack_t *head = NULL;

/**
 * main - The main entry point to the program
 * @argc: argument count; Number of command line arguments
 * @argv: argument vector; An array containing the arg.
 * Return: zero(sucess)
 */
int main(int argc, char **argv)
{
	if (argc != 2)
		error_output(1);
	open_file(argv[1]);
	free_node();
	return (0);
}
