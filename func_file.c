#include "monty.h"

/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the \
stack.
 * @l: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int l)
{
stack_t *tmp;
(void) l;
if (stack == NULL)
exit(EXIT_FAILURE);
tmp = *stack;
while (tmp != NULL)
{
printf("%d\n", tmp->n);
tmp = tmp->next;
}
}

/**
 * add_to_stack - Adds node stack.
 * @n_nd: Pointer to the new node.
 * @ln: Interger representing the line number of of the opcode.
 */
void add_to_stack(stack_t **n_nd, unsigned int ln)
{
stack_t *tmp;
(void) ln;
if (n_nd == NULL || *n_nd == NULL)
exit(EXIT_FAILURE);
if (head == NULL)
{
head = *n_nd;
return;
}
tmp = head;
head = *n_nd;
head->next = tmp;
tmp->prev = head;
}

/**
 * pop_top - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int ln)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL)
m_errors(7, ln);
tmp = *stack;
*stack = tmp->next;
if (*stack != NULL)
(*stack)->prev = NULL;
free(tmp);
}

/**
 * print_top - Prints the top node of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_top(stack_t **stack, unsigned int ln)
{
if (stack == NULL || *stack == NULL)
m_errors(6, ln);
printf("%d\n", (*stack)->n);
}









