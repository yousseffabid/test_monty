#include "monty.h"

int main(int argc, char **argv)
{
	FILE *fp;
	size_t size;
	char *line;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	line = NULL;
	size = 0;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &size, fp) != -1)
	{
		interpret_line(line, line_number, &stack);
		line_number++;
	}
	free_stack(&stack);
	free(line);
	fclose(fp);
	return (0);
}
