#include "monty.h"
/**
 * print_error - print error
 * @line: string containing the linei
 * @line_number: number of line
 * @valid_or_not: integer that tells the type of error
 * Return: void
 */
void print_error(char *line, unsigned int line_number, int valid_or_not)
{
	(void)line;

	if (valid_or_not == 0)
	{
		fprintf(stderr, "L%d: unknown instruction\n", line_number);
	}
	if (valid_or_not == -1)
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
}
