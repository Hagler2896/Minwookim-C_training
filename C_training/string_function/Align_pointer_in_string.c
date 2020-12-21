#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

void swap(char** xp, char** yp);
void printStringArray(char* arr[], int size);
void selectionSort(char* arr[], int n);

int main()
{
	char* arr[] = { "Cherry", "AppleBee", "Pineapple", "Apple", "Orange" };
	int n = sizeof(arr) / sizeof(arr[0]);

	printStringArray(arr, n);
	selectionSort(arr, n);
	printStringArray(arr, n);
	return 0;
}

void swap(char** xp, char** yp)
{
	//printf("%s\n %s\n", xp, yp);
	char* temp = *xp;
	*xp = *yp;
	*yp = temp;

}
void printStringArray(char* arr[], int size)
{
	for(int i = 0; i < size; i++)
		puts(*(arr+i));
	printf("\n");
}

void selectionSort(char* arr[], int n)
{
	int min_idx = 0;
	for (int i = 0; i < n-1; i++)
	{
		min_idx = i;
		for (int j = i; j < n; j++)
		{
			if (strcmp(arr[min_idx], arr[j]) > 0)
				min_idx = j;
			//printf("Find min_str \n");
		}
		printf("%dst min_idx = %d\n", i, min_idx);
	
		swap(&arr[i], &arr[min_idx]);
		printStringArray(arr, n);
	}
}


