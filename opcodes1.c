#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @line: line number
*/
void _add(stack_t **head, unsigned int line)
{
	stack_t *hd;
	int length = 0, ptr;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	ptr = hd->n + hd->next->n;
	hd->next->n = ptr;
	*head = hd->next;
	free(hd);
}

/**
  *_nop - doesn’t do anything.
  *@head: stack head
  *@line: line_number
 */
void _nop(stack_t **head, unsigned int line)
{
	(void) head;
	(void) line;
}

/**
  *_sub - subtracts the top element of the stack 
  *@head: head node
  *@line: line number
 */
void _sub(stack_t **head, unsigned int line)
{
	stack_t *ptr;
	int res, nodes;

	ptr = *head;
	for (nodes = 0; ptr != NULL; nodes++)
		ptr = ptr->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = *head;
	res = ptr->next->n - ptr->n;
	ptr->next->n = res;
	*head = ptr->next;
	free(ptr);
}



/**
 * _div - divides the top two elements of the stack.
 * @head: head node
 * @line: line number
*/
void _div(stack_t **head, unsigned int line)
{
	stack_t *hd;
	int length = 0, ptr;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	ptr = hd->next->n / hd->n;
	hd->next->n = ptr;
	*head = hd->next;
	free(hd);
}

/**
 * _mul - multiplies the top two elements of the stack.
 * @head: head node
 * @line: line number
*/
void _mul(stack_t **head, unsigned int line)
{
	stack_t *hd;
	int length = 0, ptr;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	ptr = hd->next->n * hd->n;
	hd->next->n = ptr;
	*head = hd->next;
	free(hd);
}
