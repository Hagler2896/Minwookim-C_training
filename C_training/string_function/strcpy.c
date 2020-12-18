#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

void my_strcpy(char* dest, char* source);
void my_strncpy(char* dest, char* source, int n);

int main()
{
	char dest[100] = "";
	char source[] = "Start programming!";

	//my_strcpy(dest, source);
	//strcpy(dest, source);
	strncpy(dest, source, 5);
	puts(dest);
	return 0;
}

void my_strcpy(char* dest, char* source)
{
	int i = 0;
	while (source[i] != '\0')
		dest[i++] = source[i];
}

void my_strncpy(char* dest, char* source, int n)
{
	int i = 0;
	while (source[i] != '\0' && i != n)
		dest[i++] = source[i];
}


