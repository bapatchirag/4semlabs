#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

int comp_count = 0;
int visited[SIZE], admat[SIZE][SIZE];

void bfs(int, int); // Traverses through the graph, breadth-first

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
            bfs(n, i);
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

void bfs(int n, int v)
{
    int q[SIZE];
    int f = 0, r = -1;
    visited[v] = 1;

    q[++r] = v;

    while(f <= r)
    {
        int deleted = q[f++];
        int x;
        for(x = 0; x < n; x++)
        {
            if(visited[x] == 0 && admat[deleted][x] == 1)
            {
                visited[x] = 1;
                q[++r] = x;
            }
        }
    }
}
