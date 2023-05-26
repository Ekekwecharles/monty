#include "monty.h"
program_data p_data = {NULL, NULL, NULL, 0};

/**
 * main - Monty byte code interpreter
 * @argc: argument count
 * @argv: comand line arguments
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	char *data;
	FILE *file = NULL;
	ssize_t readline = 1;
	stack_t *stack = NULL;
	unsigned int line = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	p_data.file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (readline > 0)
	{
		data = (char *)malloc(MAX_LINE_SIZE * sizeof(char));
		readline = fgets(data, MAX_LINE_SIZE, file) != NULL ? strlen(data) : 0;
		p_data.data = data;
		line++;
		if (readline > 0)
			exec_cmd(data, &stack, line, file);
		free(data);
	}

	free_stack(stack);
	fclose(file);
	return (EXIT_SUCCESS);
}


/**
 * exec_cmd - matches all opcodes to the various functions
 * @data: opcode from the file
 * @stack: head of linked list
 * @line: line number of the opcode
 * @file: pointer to monty file
 * Return: 0 when success
 *	1 when fail
 */
int exec_cmd(char *data, stack_t **stack, unsigned int line, FILE *file)
{
	instruction_t option[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{NULL, NULL}
	};

	unsigned int j = 0;
	char *opt;

	/* push 1$, first call to strtok gets push */
	opt = strtok(data, DELIMS);
	if (opt && opt[0] == '#')
		return (0);
	/* second call to strtok gets 1$ */
	p_data.arg = strtok(NULL, DELIMS);
	while (option[j].opcode && opt)
	{
		if (strcmp(option[j].opcode, opt) == 0)
		{
			option[j].f(stack, line);
			return (0);
		}
		j++;
	}
	if (opt && option[j].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line, opt);
		fclose(file);
		free(data);
		free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}

/**
 * free_stack - frees the stack linked list
 * @head: head node
 */
void free_stack(stack_t *head)
{
	stack_t *stack;

	stack = head;
	while (head)
	{
		stack = head->next;
		free(head);
		head = stack;
	}
}

/**
 * _free - gracefully exits the program when an errore occurs
 * @head: head node
 */
void _free(stack_t **head)
{
	fclose(p_data.file);
	free(p_data.data);
	free_stack(*head);
	exit(EXIT_FAILURE);
}
