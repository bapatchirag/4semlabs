#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int arr[SIZE];
int count = 0;

int partition(int[], int, int);
void swap(int*, int*);
void sort(int[], int, int);
void printArray(int[], int);

int main()
{
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	if(n > SIZE)
	{

		printf("Overflow!\n");
		exit(0);
	}
	
	int i;
	printf("Enter the elements: \n");
	for(i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	
	printf("Original array: \n");
	printArray(arr, n);
	printf("Soted array is: \n");
	sort(arr, 0, n - 1);
	printArray(arr, n);
	printf("No. of comparisons: %d\n", count);
	
	return 0;
}

int partition(int arr[], int l, int r)
{
	int i, j, pivot;
	pivot = arr[l];
	i = l+1, j = r;
	while(1)
	{
		while(pivot >= arr[i] && i <= r)
		{
			i++;
			count++;
		}
		while(pivot < arr[j] && j > l)
		{
			j--;
			count++;
		}
	
		if(i < j)
		{
			swap(&arr[i], &arr[j]);
		}
		else
		{	
			swap(&arr[l], &arr[j]);
			return j;
		}
	}
}

void swap(int* x, int* y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

void sort(int arr[], int l, int r)
{
	int i;
	if(l < r)
	{
		i = partition(arr, l, r);
	
		sort(arr, l, i-1);
		sort(arr, i+1, r);
	}
}

void printArray(int arr[], int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
