#include "monty.h"

/**
 * _push - pushes to top of stack
 * @head: head node
 * @line: line number
 */
void _push(stack_t **head, unsigned int line)
{
	int num, i = 0, flag = 0;

	if (p_data.arg)
	{
		if (p_data.arg[0] == '-')
			i++;
		for (; p_data.arg[i] != '\0'; i++)
		{
			if (p_data.arg[i] > 57 || p_data.arg[i] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line);
			fclose(p_data.file);
			free(p_data.data);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(p_data.arg);
	if (p_data.lifi == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}

/**
 * _pall - prints all data
 * @head: head node
 * @line: unsused
 */
void _pall(stack_t **head, __attribute__((unused)) unsigned int line)
{
	stack_t *hd;

	hd = *head;
	if (hd == NULL)
		return;
	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}

/**
 * _pint - prints only the top
 * @head: head node
 * @line: line number
 */
void _pint(stack_t **head, unsigned int line)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
 * _pop - removes the top
 * @head: head node
 * @line: line number
 */
void _pop(stack_t **head, unsigned int line)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line);
		fclose(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}

/**
 * _swap - swaps the top two elements of the stack.
 * @head: stack head
 * @line: line number
*/
void _swap(stack_t **head, unsigned int line)
{
	stack_t *hd;
	int length = 0, ptr;

	hd - *head;
	while (h)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line);
		fclode(p_data.file);
		free(p_data.data);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	ptr = hd->n;
	hd->n = hd->next->n;
	hd->next->n = ptr;
}

