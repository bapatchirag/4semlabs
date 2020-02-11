#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int comp_count = 0;
int visited[SIZE], admat[SIZE][SIZE];

void dfs(int, int); // Traverses through the graph, depth-first

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
}
