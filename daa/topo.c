#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int visited[SIZE], admat[SIZE][SIZE];
int tstack[SIZE], top = -1;

void dfs(int, int); // Traverses through the graph, depth-first
void printStack(int[], int); // Prints list in reverse

int main()
{
    int n = 0;
    printf("Enter number of vertices in graph: ");
    scanf("%d", &n);

    int i, j;
    printf("Enter adjacency matrix of the graph: \n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &admat[i][j]);
        }
    }

    for(i = 0; i < n; i++)
    {
        if(visited[i] == 0)
        {
            dfs(n, i);
        }
    }

    printf("Topological order is: \n");
    printStack(tstack, top);

    return 0;
}

void dfs(int n, int v)
{
    visited[v] = 1;
    int x;
    for(x = 0; x < n; x++)
    {
        if(visited[x] == 0 && admat[v][x] == 1)
        {
            dfs(n, x);
        }
    }
    tstack[++top] = v;
}

void printStack(int arr[], int n)
{
	int i;
	for(i = n; i >= 0; i--)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}
