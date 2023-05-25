#include "monty.h"

/**
 * addnode - adds new node
 * @head: head node
 * @num: num value
 */
void addnode(stack_t **head, int num)
{
	stack_t *new_node, *ptr;

	ptr = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	if (ptr)
		ptr->prev = new_node;
	new_node->n = num;
	new_node->next = *head;
	new_node->prev = NULL;
	*head = new_node;
}

/**
 * addqueue - adds new node to the queue
 * @head: head node
 * @num: num value:
 */
void addqueue(stack_t **head, int num)
{
	stack_t *new_node, *ptr;

	ptr = *head;
	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->next = NULL;
	if (ptr)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	if (!ptr)
	{
		*head = new_node;
		new_node->prev = NULL;
	}
	else
	{
		ptr->next = new_node;
		new_node->prev = ptr;
	}
}
