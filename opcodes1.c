#include "monty.h"
/**
 * _add - adds the top two elements of the stack.
 * @head: stack head
 * @line: line number
*/
void f_add(stack_t **head, unsigned int line)
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
void f_nop(stack_t **head, unsigned int line)
{
	(void) head;
	(void) line;
}
