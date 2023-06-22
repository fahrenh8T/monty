#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdarg.h>
#include <ctype.h>
#include <fcntl.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
		int n;
		struct stack_s *prev;
		struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
		char *opcode;
		void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;

typedef void (*op_func)(stack_t **, unsigned int);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

void push(stack_t **stack, unsigned int num);
void pall(stack_t **stack, unsigned int num);
void pint(stack_t **stack, unsigned int num);
void pop(stack_t **stack, unsigned int num);
void swap(stack_t **stack, unsigned int num);
void add(stack_t **stack, unsigned int num);
void nop(stack_t **stack, unsigned int num);

void sub(stack_t **stack, unsigned int num);
void divd(stack_t **stack, unsigned int num);
void mult(stack_t **stack, unsigned int num);
void add_queue(stack_t **stack, unsigned int num);

int main(int argc, char **argv);
void open_file(char *f_name);
void read_file(FILE *fd);
int interp_line(char *string, int n_line, int format);
stack_t *new_node(int n);
void free_node(void);
void error_output(unsigned int error_c, ...);
void error_output2(unsigned int error_c, ...);
void srch_func(char *opcode, char *comd, int n_line, int format);
void find_function(op_func f, char *op_code, char *cmd, int n_line, int frmat);

#endif /*MONTY_H*/
