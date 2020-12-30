#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "my_rand.h"

#pragma warning(disable: 4996)


int main()
{
	my_srand((unsigned int)time(0));

	for (int i = 0; i < 10; ++i)
	{
		printf("%d\n", my_rand() % 6 + 1);
	}

	return 0;
}