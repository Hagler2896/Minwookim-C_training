#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

#define SLEN 30

struct namect{
	char* fname;
	char* lname;
	int letters;
};

void getinfo(struct namect*);
void makeinfo(struct namect*);
void showinfo(const struct namect*);
void cleanup(struct namect*);
char* s_gets(char* st, int n);


int main()
{
	struct namect person;

	getinfo(&person);
	makeinfo(&person);
	showinfo(&person);
	cleanup(&person);

	return 0;
}

void getinfo(struct namect* ct)
{
	char buffer[SLEN] = { 0, }; 
	printf("Please enter your first name.\n");
	int f1 = scanf("%[^\n]%*c", buffer);
	ct->fname = (char*)malloc(strlen(buffer) + 1);  
	
	if (ct->fname != NULL) 
		strcpy(ct->fname, buffer); 

	
	printf("Please enter your last name.\n");
	int f2 = scanf("%[^\n]%*c", buffer);
	ct->lname = (char*)malloc(strlen(buffer) + 1);
	if (ct->lname != NULL)
		strcpy(ct->lname, buffer);
}

void makeinfo(struct namect* ct)
{
	ct->letters = strlen(ct->fname) + strlen(ct->lname);
}

void showinfo(const struct namect* ct)
{
	printf("%s %s. your name contains %d letters.\n", ct->fname, ct->lname, ct->letters);
}

void cleanup(struct namect* ct)
{
	free(ct->fname);
	free(ct->lname);
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