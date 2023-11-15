#include "monty.h"

/**
 * print_char - Prints the Ascii value.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of of the opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
int a;
if (stack == NULL || *stack == NULL)
string_err(11, line_number);
a = (*stack)->n;
if (a < 0 || a > 127)
string_err(10, line_number);
printf("%c\n", a);
}

/**
 * print_str - Prints a string.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @ln: Interger representing the line number of of the opcode.
 */
void print_str(stack_t **stack, unsigned int ln)
{
int a;
stack_t *tmp;
(void) ln;
if (stack == NULL || *stack == NULL)
{
printf("\n");
return;
}
tmp = *stack;
while (tmp != NULL)
{
a = tmp->n;
if (a <= 0 || a > 127)
break;
printf("%c", a);
tmp = tmp->next;
}
printf("\n");
}
