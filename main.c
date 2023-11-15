#include "monty.h"
stack_t *head = NULL;

/**
 * main - entry point
 * @ac: arguments count
 * @av: list of arguments
 * Return: always 0
 */

int main(int ac, char *av[])
{
if (ac != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
open_file(av[1]);
free_nodes();
return (0);
}

/**
 * create_node - Creates a node.
 * @n: Number to go inside the node.
 * Return: Upon sucess a pointer to the node. Otherwise NULL.
 */
stack_t *create_node(int n)
{
stack_t *nd;
nd = malloc(sizeof(stack_t));
if (nd == NULL)
errors(4);
nd->next = NULL;
nd->prev = NULL;
nd->n = n;
return (nd);
}

/**
 * free_nodes - Frees nodes in the stack.
 */
void free_nodes(void)
{
stack_t *tmp;
if (head == NULL)
return;
while (head != NULL)
{
tmp = head;
head = head->next;
free(tmp);
}
}


/**
 * add_to_queue - Add the node to queue.
 * @n_node: Pointer to the new node.
 * @line_n: line number of the opcode.
 */
void add_to_queue(stack_t **n_node, unsigned int line_n)
{
stack_t *tmp;
(void) line_n;
if (n_node == NULL || *n_node == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *n_node;
return;
}
tmp = head;
while (tmp->next != NULL)
tmp = tmp->next;
tmp->next = *n_node;
(*n_node)->prev = tmp;
}
