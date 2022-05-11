#include "monty.h"

void print_error(char *line, unsigned int line_number, int valid_or_not)
{
	unsigned int len;

	if (valid_or_not == 0)
	{
		len = strlen(line);
		fprintf(stderr, "L%d: unknown instruction\n", line_number);
		perror("");
		perror(line);
		perror(line + len);
	}
	if (valid_or_not == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		perror("");
	}
}
