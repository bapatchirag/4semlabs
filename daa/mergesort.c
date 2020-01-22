#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int arr[SIZE];
int count = 0;

void merge(int[], int, int, int);
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

void merge(int arr[], int l, int r, int m)
{
	int initial[SIZE], final[SIZE];
	
	// Copy elements from initial half of array
	int i;
	for(i = 0; i < m-l+1; i++)
	{
		initial[i] = arr[i+l];
	}
	
	// Copy elements from final part of array
	for(i = 0; i <= r-m; i++)
	{
		final[i] = arr[m+1+i];
	}
	
	// Merge back into array
	int i1 = 0, i2 = 0;
	while(i1 < m+1-l && i2 < r-m)
	{
		count++;
		if(initial[i1] <= final[i2])
		{
			arr[i1+i2+l] = initial[i1];
			i1++;
		}
		else
		{
			arr[i1+i2+l] = final[i2];
			i2++;
		}
	}
	
	// Remaining elements of initial
	while(i1 < m+1-l)
	{
		arr[i1+i2+l] = initial[i1];
		i1++;
	}
	
	// Remaining elements of final
	while(i2 < r-m)
	{
		arr[i1+i2+l] = final[i2];
		i2++;
	}
}

void sort(int arr[], int l, int r)
{
	int m = (l + r) / 2;
	if(l < r)
	{
		sort(arr, l, m);
		sort(arr, m + 1, r);
		
		merge(arr, l, r, m);
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
