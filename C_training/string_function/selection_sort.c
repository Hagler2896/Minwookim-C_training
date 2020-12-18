#include <stdio.h>
#include <string.h>

#pragma warning(disable: 4996)

void swap(int* xp, int* yp);
void printArray(int arr[], int size);
void selectionSort(int arr[], int n);

int main()
{
	//int arr[] = { 64, 25, 12, 22, 11 };
	int arr[] = { 45, 29, 345, 72, 63 };
	//int arr[] = { 9, 1, 3, 7, 5 };
	int n = sizeof(arr) / sizeof(arr[0]);

	selectionSort(arr, n);

	printArray(arr, n);

	return 0;
}

void swap(int* xp, int* yp)
{
	int temp = *yp; 
	*yp = *xp; 
	*xp = temp;

}

void printArray(int arr[], int size)
{
	for (int i = 0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void selectionSort(int arr[], int n)
{
	int min_idx = 0;

	for (int j = 0; j < n - 1; j++)
	{
		min_idx = j;
		for (int i = j + 1 ; i < n; i++)
		{
			if (arr[min_idx] > arr[i])
				min_idx = i;
		}
		swap(&arr[j], &arr[min_idx]);
	}
}



