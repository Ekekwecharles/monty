#include "monty.h"
/**
 * _mod - multiplies the top two elements of the stack.
 * @head: head node
 * @line: line number
*/
void _mod(stack_t **head, unsigned int line)
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
		fprintf(stderr, "L%d: can't mod, stack too short\n", line);
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
	ptr = hd->next->n % hd->n;
	hd->next->n = ptr;
	*head = hd->next;
	free(hd);
}
