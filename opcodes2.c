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
		cleanupAndExit(head);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line);
		cleanupAndExit(head);
	}
	ptr = hd->next->n % hd->n;
	hd->next->n = ptr;
	*head = hd->next;
	free(hd);
}

/**
 * _pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: head node
 * @line: line counter
*/
void _pchar(stack_t **head, unsigned int line)
{
	stack_t *hd;

	hd = *head;
	if (!hd)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", line);
		cleanupAndExit(head);
	}
	if (hd->n > 127 || hd->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", line);
		cleanupAndExit(head);
	}
	printf("%c\n", hd->n);
}

/**
 * _pstr - prints the string starting at the top of the stack
 * @head: top of the stack
 * @line: unused
 */
void _pstr(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *hd;

	hd = *head;
	while (hd)
	{
		if (hd->n > 127 || hd->n <= 0)
			break;
		printf("%c", hd->n);
		hd = hd->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @head: top of stack
 * @line: unused
 */
void _rotl(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *temp = *head, *ptr;

	if (*head == NULL || (*head)->next == NULL)
		return;
	ptr = (*head)->next;
	ptr->prev = NULL;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = *head;
	(*head)->next = NULL;
	(*head)->prev = temp;
	(*head) = ptr;
}

/**
 * _rotr -  rotates the stack to the bottom.
 * @head: top of stack
 * @line: unused
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *cpy;

	cpy = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;
	while (cpy->next)
		cpy = cpy->next;
	cpy->next = *head;
	cpy->prev->next = NULL;
	cpy->prev = NULL;
	(*head)->prev = cpy;
	(*head) = cpy;
}
