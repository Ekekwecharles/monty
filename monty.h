#ifndef MONTY_H
#define MONTY_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <unistd.h>

#define DELIMS " \n\t"
#define MAX_LINE_SIZE 1024


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

typedef struct programdata
{
	char *arg;
	FILE *file;
	char *data;
	int lifi;
} program_data;
extern program_data p_data;

void _pall(stack_t **head, __attribute__((unused)) unsigned int line);
void _push(stack_t **head, unsigned int line);
void free_stack(stack_t *head);
int exec_cmd(char *data, stack_t **stack, unsigned int line, FILE *file);
void addnode(stack_t **head, int num);
void addqueue(stack_t **head, int num);
void _pint(stack_t **head, unsigned int line);
void _pop(stack_t **head, unsigned int line);
#endif
