#include <stdio.h>

int strcmp(const char* str1, const char* str2);
int strncmp(const char* str1, const char* str2, int len);

int main()
{
	printf("%d\n", strcmp("Banana", "Banana"));
	printf("%d\n", strncmp("BlockDmask", "BlockFmask",5));
	return 0;
}

int strcmp(const char* str1, const char* str2)
{
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		else
		{
			str1++;
			str2++;
		}
	}

	return 0;
}

int strncmp(const char* str1, const char* str2, int len)
{
	int count = 0;
	while (*str1 != '\0' || *str2 != '\0')
	{
		if (count == len)
			break;
		else if (*str1 > *str2)
			return 1;
		else if (*str1 < *str2)
			return -1;
		else
		{
			str1++;
			str2++;
			count++;
		}
	}

	return 0;
}

