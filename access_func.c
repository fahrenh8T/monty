#include "monty.h"
/**
 * open_file - Function that opens a file
 * @f_name: This a string with the name of the file
 */
void open_file(char *f_name)
{
	int f_check;
	FILE *fd;

	if (f_name == NULL)
		error_output(2, f_name);

	f_check = access(f_name, R_OK);
	if (f_check == -1)
		error_output(2, f_name);
	fd = fopen(f_name, "r");
	if (fd == NULL)
		error_output(2, f_name);
	read_file(fd);

	fclose(fd);
}
/**
 * read_file - Reads the file
 * @fd: Pointer to a file descriptor
 */
void read_file(FILE *fd)
{
	int n_line;
	int format = 0;
	char *buff = NULL;
	size_t n = 0;

	if (fd == NULL)
		error_output(2, "f_name");
	/*Read line by line*/
	for (n_line = 1; getline(&buff, &n, fd) != EOF; n_line++)
	{
		format = interp_line(buff, n_line, format);
	}
	free(buff);
}
/**
 * interp_line - function that interprates each line
 * @string: String to be read
 * @n_line: line for operationalcode
 * @format: format specifier is 0 for Stack 1 for Queue
 * Return: 0 if the opcode is stack or 1 if Queue.
 */
int interp_line(char *string, int n_line, int format)
{
	char *op_code;
	char *comd;
	const char *delm;

	delm = "\n ";

	if (string == NULL)
		error_output(4);

	op_code = strtok(string, delm);

	if (op_code == NULL)
		return (format);

	comd = strtok(NULL, delm);
	if (strcmp(op_code, "queue") == 0)
		return (1);
	else if (strcmp(op_code, "stack") == 0)
		return (0);

	srch_func(op_code, comd, n_line, format);
	return (format);
}
