#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>

#pragma warning(disable: 4996)

void ToUpper(char* str)
{
	while (*str)
	{
		*str = toupper(*str);
		str++;
	}
 }

void ToLower(char* str)
{
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
}

void UpdateString(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

int main()
{
	char str[] = "Hello, World!";

	void(*pf)(char*);
	pf = ToUpper;

	(*pf)(str);
	printf("ToUpper : %s\n", str);

	pf = ToLower;

	(*pf)(str);
	printf("ToLower : %s\n", str);

	UpdateString(str, toupper);

	printf("ToLower : %s\n", str);

	UpdateString(str, tolower);

	printf("ToLower : %s\n", str);
	return 0;
}

