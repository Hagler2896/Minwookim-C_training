#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#pragma warning(disable: 4996)

#define SLEN 101

struct book
{
	char name[SLEN];
	char author[SLEN];
};

void print_books(const struct book* books, int n);
void write_books(const char * filename, const struct book* books, int n);
struct book* read_books(const char* filename, int* n);
void read_books2(const char* filename, struct book** books_dptr, int* n);

int main()
{
	int temp;
	int n = 3;
	
	struct book* my_books = (struct book*) malloc(sizeof(struct book) * 3);

	if (!my_books) {
		printf("Malloc failed");
		exit(1);
	}

	my_books[0] = (struct book) { "The Great Gatsby", "F. Scott Fitzgerald" };
	my_books[1] = (struct book) { "Hamlet", "William Shakespeare" };
	my_books[2] = (struct book) { "The Odyssey", "Homer" };

	print_books(my_books, n);

	printf("\nWriting to a file.\n");
	write_books("books.txt", my_books, n);
	free(my_books);
	n = 0;
	printf("Done.\n");

	printf("\nPress any key to read data from a file.\n\n");
	temp = _getch();

	my_books = read_books("books.txt", &n);
	//read_books2("books.txt", &my_books, &n);
	print_books(my_books, n);
	free(my_books);
	n = 0;

	return 0;
}

void print_books(const struct book* books, int n)
{
	for (int i = 0; i < n; ++i)
		printf("Book%d : \"%s\" Written by \"%s\"\n",
			i + 1, books[i].name, books[i].author);
}

void write_books(const char * filename, const struct book* books, int n)
{
	FILE* fr;

	if ((fr = fopen(filename, "w")) == NULL)
	{
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}
	
	fprintf(fr, "%d\n", n);
	
	for (int i = 0; i < n; ++i)
	{
		fprintf(fr, "%s\n%s\n", books[i].name, books[i].author);
	}

	fclose(fr);
}

//struct book* read_books(const char* filename, int* n)
//{
//	FILE* fw;
//	char buffer[SLEN];
//
//	if ((fw = fopen(filename, "r")) == NULL)
//	{
//		printf("Can't open %s\n", filename);
//		exit(EXIT_FAILURE);
//	}
//	
//	*n = fgetc(fw) - '0'; // n 업데이트
//	
//	struct book* my_books = (struct book*) malloc(sizeof(struct book) * *n); // 동적 할당
//	fgetc(fw);
//	
//	for (int i = 0; i < *n; ++i)
//	{
//		fgets(&buffer, SLEN, fw);
//
//		char* temp;
//		temp = strchr(&buffer, '\n');
//		*temp = '\0';
//		strcpy(my_books[i].name, buffer);
//		
//		fgets(&buffer, SLEN, fw);
//		temp = strchr(&buffer, '\n');
//		*temp = '\0';
//		strcpy(my_books[i].author, buffer);
//	}
//	
//	return my_books;
//}


struct book* read_books(const char* filename, int* n)
{
		FILE* fr;
	
		if ((fr = fopen(filename, "r")) == NULL)
		{
			printf("Can't open %s\n", filename);
			exit(EXIT_FAILURE);
		}
		
		int flag;
		flag = fscanf(fr, "%d%*c", n);
		
		struct book* my_books = (struct book*) calloc(sizeof(struct book), *n); // 동적 할당

		if (!my_books)
		{
			printf("Calloc() failed.");
			exit(1);
		}

		for (int i = 0; i < *n; ++i)
		{
			flag = fscanf(fr, "%[^\n]%*c%[^\n]%*c", my_books[i].name, my_books[i].author);
		}

		fclose(fr);

		return my_books;
}

void read_books2(const char* filename, struct book** books_dptr, int* n)
{
	FILE* fr;

	if ((fr = fopen(filename, "r")) == NULL)
	{
		printf("Can't open %s\n", filename);
		exit(EXIT_FAILURE);
	}

	int flag;
	flag = fscanf(fr, "%d%*c", n);

	struct book* my_books = (struct book*) calloc(sizeof(struct book), *n); // 동적 할당

	if (!my_books)
	{
		printf("Calloc() failed.");
		exit(1);
	}

	for (int i = 0; i < *n; ++i)
	{
		flag = fscanf(fr, "%[^\n]%*c%[^\n]%*c", my_books[i].name, my_books[i].author);
	}

	fclose(fr);

	*books_dptr =  my_books;
}
