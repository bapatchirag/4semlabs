#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int n;							// Number of vertices of graph
int visited[SIZE], admat[SIZE][SIZE], indegree[SIZE];	// Visited, adjacency matrix and indegree lists
int queue[SIZE], fq = 0, rq = -1;			// Queue of vertices with indegrees 0
int order[SIZE], fo = 0, ro = -1;			// Topological order

void vertexdel();					// Main vertex deletion
void printList(int[], int);				// Helper function to print list
int countVisited();					// Helper function to count number of visited vertices

int main()
{
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	
	int i, j;
	printf("Enter adjacency matrix: \n");
	for(i = 0; i < n; i++)
	{
		for(j= 0; j < n; j++)
		{
			scanf("%d", &admat[i][j]);
			if(admat[i][j] == 1)
			{
				indegree[j]++;
			}
		}
	}
	
	vertexdel();
	printf("Topological ordering: \n");
	printList(order, n);
	
	return 0;
}

int countVisited()
{
	int i, count = 0;
	for(i = 0; i < n; i++)
	{
		if(visited[i] == 1)
			count++;
	}
	
	return count;
}

void vertexdel()
{
	if(countVisited() == n)
	{
		return;
	}
	
	int i, j;
	for(i = 0; i < n; i++)
	{
		if(indegree[i] == 0 && visited[i] == 0)
		{
			queue[++rq] = i;
		}
	}
	
	for(i = fq; i <= rq; i++)
	{
		int current = queue[i];
		order[++ro] = current;
		visited[current] = 1;
		
		for(j = 0; j < n; j++)
		{
			if(admat[current][j] == 1 && visited[j] == 0 && indegree[j] != 0)
			{
				indegree[j]--;
			}
		}
		fq++;
	}	
	
	vertexdel();
}

void printList(int arr[], int size)
{
	int i;
	for(i = 0; i < size; i++)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
