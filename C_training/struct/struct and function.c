#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

#define NLEN 30

struct name_count {
	char first[NLEN];
	char last[NLEN];
	int num;
};

void receive_input(struct name_count*);
void count_characters(struct name_count*);
void show_result(const struct name_count*);
char* s_gets(char* st, int n);


int main()
{
	struct name_count user_name;

	receive_input(&user_name);
	count_characters(&user_name);
	show_result(&user_name);
	return 0;
}

void receive_input(struct name_count* ptr)
{
	int flag;
	printf("Input your first name:\n>> ");
	//s_gets(ptr->first, NLEN);
	flag = scanf("%[^\n]%*c", ptr->first);
	if (flag != 1)
		printf("Wrong input");

	printf("Input your last name:\n>> ");
	flag = scanf("%[^\n]%*c", ptr->last);
	if (flag != 1)
		printf("Wrong input");
	//s_gets(ptr->last, NLEN);
}

void count_characters(struct name_count* ptr)
{
	ptr->num = strlen(ptr->first) + strlen(ptr->last);
}

void show_result(const struct name_count* ptr)
{
	printf("Hi, %s %s. Your name has %d characters.\n", 
		ptr->first, ptr->last, ptr->num);
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(ret_val, '\n');
		if (find)
			*find = '\0';
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}

//char* s_gets(char* st, int n)
//{
//	int place = 0;
//	char* str = fgets(st, n, stdin);
//	while (*str++ != '\n')
//	{
//		place++;
//	}
//	st[place] = '\0';
//}