#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>

#pragma warning(disable: 4996)

void update_string(char* str, int(*pf)(int));
void ToUpper(char* str);
void ToLower(char* str);
void Transpose(char* str);

int main()
{
	char options[] = { 'u', 'l', 't' };
	int n = sizeof(options) / sizeof(options[0]);

	typedef void(*FUNC_TYPE)(char*);	// char*을 인자로 받고 리턴타입이 void인 FUNC_TYPE이라는 함수포인터 선언
	FUNC_TYPE operations[] = { ToUpper, ToLower, Transpose};	// 함수 포인터의 배열 생성

	printf("Enter a string\n>> ");

	char input[100];

	while (scanf("%[^\n]%*c", input) != 1)
		printf("Please try again.\n>> ");
	while (true)
	{
		printf("Choose an option:\n");
		puts("u) to upper");
		puts("l) to lower");
		puts("t) to transpose");

		char c;
		while (scanf("%c%[^\n]%*c", &c) != 1)
			printf("Plase try again.\n");

		bool found = false;

		for (int i = 0; i < n; ++i)
		{
			if (options[i] == c) {
				(*(operations[i]))(input);
				found = true;
				break;
			}
		}

		if (found)
			break;
		else
			printf("Wrong input, try again.\n");
	}
	printf("%s\n", input);
	return 0;
}

void update_string(char* str, int(*pf)(int))
{
	while (*str)
	{
		*str = (*pf)(*str);
		str++;
	}
}

void ToUpper(char* str)
{
	update_string(str, toupper);
}

void ToLower(char* str)
{
	update_string(str, tolower);
}

void Transpose(char* str)
{
	while (*str)
	{
		if (islower(*str))
			*str = toupper(*str);
		else if (isupper(*str))
			*str = tolower(*str);
		str++;
	}
}
