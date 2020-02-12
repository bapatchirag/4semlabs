#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int comp_count = 0;
int visited[SIZE], admat[SIZE][SIZE];
int order[SIZE], f = 0, r = -1;

void dfs(int, int); // Traverses through the graph, depth-first
void addOrder(int); // Adds to order array
int countVisited(int); // Counts visited vertices
void printList(int[], int); // Prints given array of given size

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
            addOrder(i);
            dfs(n, i);
            comp_count++;
        }
    }

    if(comp_count == 1)
    {
        printf("Connected graph\n");
    }
    else
    {
        printf("Disconnected graph with %d components\n", comp_count);
    }

    printf("The DFS order is: \n");
    printList(order, countVisited(n));

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
            addOrder(x);
            dfs(n, x);
        }
    }
}

void addOrder(int x)
{
    if(r == -1)
    {
        order[++r] = x;
        return;
    }

    int i;
    for(i = f; i <= r; i++)
    {
        if(order[i] == x)
        {
            return;
        }
    }
    order[++r] = x;
}

int countVisited(int n)
{
	int count = 0, i;
	for(i = 0; i < n; i++)
	{
		if(visited[i] == 1)
		{
			count++;
		}
	}
	
	return count;	
}

void printList(int arr[], int n)
{
    int i;
    for(i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
}
