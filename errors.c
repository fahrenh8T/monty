#include "monty.h"
/**
 * error_output - handles and prints all error messages
 * @error_c: shows the various number of errors encountered
 */
void error_output(unsigned int error_c, ...)
{
	va_list ag;
	char *op_err;
	unsigned int line_c;

	va_start(ag, error_c);

	switch (error_c)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
					va_arg(ag, char *));
			break;
		case 3:
			line_c = va_arg(ag, unsigned int);
			op_err = va_arg(ag, char *);
			fprintf(stderr, "L%u: unknown instruction %s\n", line_c, op_err);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%u: usage: push integer\n", va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}

/**
 * error_output2 - handles and prints all error messages
 * @error_c: shows the various number of errors encountered
 */
void error_output2(unsigned int error_c, ...)
{
	va_list ag;
	char *op_err;
	unsigned int line_c;

	va_start(ag, error_c);
	switch (error_c)
	{
		case 6:
			fprintf(stderr, "L%u: can't pint, stack empty\n",
					va_arg(ag, unsigned int));
			break;
		case 7:
			fprintf(stderr, "L%u: can't pop an empty stack\n",
					va_arg(ag, unsigned int));
			break;
		case 8:
			line_c = va_arg(ag, unsigned int);
			op_err = va_arg(ag, char *);
			fprintf(stderr, "L%u: can't %s, stack too short\n", line_c, op_err);
			break;
		case 9:
			line_c = va_arg(ag, unsigned int);
			op_err = va_arg(ag, char *);
			fprintf(stderr, "L%u: can't div %s, stack too short \n",
					line_c, op_err);
			break;
		default:
			break;
	}
	free_node();
	exit(EXIT_FAILURE);
}
