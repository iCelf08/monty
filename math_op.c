#include "monty.h"

/**
 * mul_nodes - multiplies the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
int mul;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_errors(8, line_number, "mul");
(*stack) = (*stack)->next;
mul = (*stack)->n * (*stack)->prev->n;
(*stack)->n = mul;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * mod_nodes - modules the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
int mod;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_errors(8, line_number, "mod");
if ((*stack)->n == 0)
m_errors(9, line_number);
(*stack) = (*stack)->next;
mod = (*stack)->n % (*stack)->prev->n;
(*stack)->n = mod;
free((*stack)->prev);
(*stack)->prev = NULL;
}

/**
 * mod_nodes - modules the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
int div;
if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
m_errors(8, line_number, "div");
if ((*stack)->n == 0)
m_errors(9, line_number);
(*stack) = (*stack)->next;
div = (*stack)->n / (*stack)->prev->n;
(*stack)->n = div;
free((*stack)->prev);
(*stack)->prev = NULL;
}
