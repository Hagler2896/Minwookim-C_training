#include <stdio.h>
#include <string.h>
#include <ctype.h>

#pragma warning(disable: 4996)

#define NUM_LIMIT 1024

void ToUpper(char*);
int PunctCount(const char*);


int main()
{
	char line[NUM_LIMIT];
	char* new_line = NULL;
	fgets(line, NUM_LIMIT, stdin);
	new_line = strchr(line, '\n');
	if (new_line)
		*new_line = '\0';

	ToUpper(line);
	puts(line);
	printf("%d\n", PunctCount(line));
}


void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
}

int PunctCount(const char* str)
{
	int ct = 0;

	while (*str)
	{
		if (ispunct(*str))
			ct++;
		str++;
	}
	return ct;
}
