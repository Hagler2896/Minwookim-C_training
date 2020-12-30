#include <stdio.h>
#include <stdlib.h>

#pragma warning(disable: 4996)


int main(int argc, char* argv[])
{
	int ch;
	FILE* fr;

	unsigned long count = 0;

	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	if ((fr = fopen(argv[1], "r")) == NULL)
	{
		printf("Can't open %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((ch = fgetc(fr)) != EOF)
	{
		fputc(ch, stdout);

		count++;
	}

	fclose(fr);

	printf("FILE %s has %lu characters\n", argv[1], count);

}