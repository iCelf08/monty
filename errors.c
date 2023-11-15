#include "monty.h"

/**
 * errors - prints error message by error code.
 *@error_code:
 * -1:wrong argument file
 * -2:file can not be open
 * -3:invalid instruction
 * -4:malloc error
 * -5:push wrong parametre
*/

void errors(int error_code, ...)
{
va_list ag;
char *operation;
int l;
va_start(ag, error_code);
 switch (error_code)
 {
case 1:
fprintf(stderr, "USAGE: monty file\n");
break;
case 2:
fprintf(stderr, "Error: Can't open file %s\n", va_arg(ag, char*));
break;
case 3:
l = va_arg(ag, int);
operation = va_arg(ag, char*);
fprintf(stderr, "L%d: unknown instruction %s\n", l, operation);
break;
case 4:
fprintf(stderr, "Error: malloc failed\n");
break;
case 5:
fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}

/**
 *m_errors - prints error message by error code.
 *@error_code:
 * -6:pint stack is empty
 * -7:pop stack is empty
 * -8:stack is too short
 * -9: dividion by 0 
 */
void m_errors(int error_code, ...)
{
va_list ag;
char *op;
int l;
va_start(ag, error_code);
switch (error_code)
{
case 6:
fprintf(stderr, "L%d: can't pint, stack empty\n", va_arg(ag, int));
break;
case 7:
fprintf(stderr, "L%d: can't pop an empty stack\n", va_arg(ag, int));
break;
case 8:
l = va_arg(ag, int);
op = va_arg(ag, char*);
fprintf(stderr, "L%d: can't %s, stack too short\n", l, op);
break;
case 9:
fprintf(stderr, "L%d: division by zero\n", va_arg(ag, unsigned int));
break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}


/**
 * string_err - handles errors.
 * @error_code: are:
 * -10:The number inside a node is outside ASCII bounds.
 * -11:The stack is empty.
 */
void string_err(int error_code, ...)
{
va_list argument;
int l_num;
va_start(argument, error_code);
l_num = va_arg(argument, int);
switch (error_code)
{
case 10:
fprintf(stderr, "L%d: can't pchar, value out of range\n", l_num);
break;
case 11:
fprintf(stderr, "L%d: can't pchar, stack empty\n", l_num);break;
default:
break;
}
free_nodes();
exit(EXIT_FAILURE);
}
