#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma warning(disable: 4996)

struct names
{
	char first[20];
	char last[20];
};

struct person
{
	int id;
	struct names name;
};

struct person2
{
	int id;
	struct { char first[20]; char last[20]; };	// anonymous structure
};
int main()
{
	struct person ted = { 123, {"Bill", "Gates"} };
	struct person2 ted3 = { 125, "Robert", "Hand" };

	puts(ted.name.first);
	puts(ted.name.last);

	struct person2 ted2 = { 124, {"Steve", "wozniak"} };
	puts(ted2.first);
	return 0;
}
