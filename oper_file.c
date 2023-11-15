#include "monty.h"

/**
 * nop - Doesn't do  anything.
 * @stack: top node the stack.
 * @ln:line number of  opcode.
 */
void nop(stack_t **stack, unsigned int ln)
{
(void)stack;
(void)ln;
}

/**
 * swap_nodes - Swaps top two elements of stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln:line number of the opcode.
 */
void swap_nodes(stack_t **stack, unsigned int ln)
{
stack_t *tmp;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_errors(8, ln, "swap");
tmp = (*stack)->next;
(*stack)->next = tmp->next;
if (tmp->next != NULL)
tmp->next->prev = *stack;
tmp->next = *stack;
(*stack)->prev = tmp;
tmp->prev = NULL;
*stack = tmp;
}

/**
 * add_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
int dup;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_errors(8, line_number, "add");
(*stack) = (*stack)->next;
dup = (*stack)->n + (*stack)->prev->n;
(*stack)->n = dup;
free((*stack)->prev);
(*stack)->prev = NULL;
}


/**
 * sub_nodes - Adds the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
int dup;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_errors(8, line_number, "sub");
(*stack) = (*stack)->next;
dup  = (*stack)->n - (*stack)->prev->n;
(*stack)->n = dup;
free((*stack)->prev);
(*stack)->prev = NULL;
}

