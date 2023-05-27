#include "monty.h"

/**
 * _stack - sets the format of the data to a stack (LIFO)
 * @head: unused
 * @line: unused
 *
 * Description: This is the default behavior of the program.
 */
void _stack(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
	p_data.lifi = 0;
}

/**
 * _queue - sets the format of the data to a queue (FIFO)
 * @head: unused
 * @line: unused
 */
void _queue(stack_t **head, unsigned int line)
{
	(void)head;
	(void)line;
	p_data.lifi = 1;
}
