#include "monty.h"
/**
 * print_error - print error
 * @line: string containing the linei
 * @line_number: number of line
 * Return: void
 */
void print_error(char *line, unsigned int line_number)
{
	(void)line;

	fprintf(stderr, "L%d: unknown instruction\n", line_number);
}
