#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);

int main()
{
	//struct book my_books[3];
	struct book* my_books = (struct book*) malloc(sizeof(struct book) * 3);

	if (!my_books) {
		printf("Malloc failed");
		exit(1);
	}

	my_books[0] = (struct book) { "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book) { "The Hamlet Gatsby", "William Shakespeare" };
	my_books[2] = (struct book) { "The Odyssey", "Homer" };

	print_books(my_books, 3);

	return 0;
}

void print_books(const struct book* books, int n)
{
	for(int i = 0; i < n; ++i)
		printf("Book%d : \"%s\" Written by \"%s\"\n", 
			i+1, books[i].name, books[i].author);
}
