#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

// Graph, tree and vertices visited during tree generation
int graph[SIZE][SIZE], number_of_vertices;
int tree[SIZE][SIZE];
int visited_vertices[SIZE], vertex_count = 0;

// Tree generator function
int prim(int[SIZE][SIZE], int, int);

// Helper function
int isCycle(int[], int, int);
void printMatrix(int[SIZE][SIZE], int, int);

int main() {
	printf("Enter number of vertices in the graph: ");
	scanf("%d", &number_of_vertices);

	int i, j;
	printf("Enter the weighted adjacency matrix of graph: \n");
	for(i = 0; i < number_of_vertices; i++)
		for(j = 0; j < number_of_vertices; j++)
			scanf("%d", &graph[i][j]);

	int ch;
	printf("Enter 1 for digraph, 0 for simple graph: ");
	scanf("%d", &ch);

	printf("Weight of minimum spanning tree is: %d\n", prim(graph, number_of_vertices, ch));
	printf("Minimum spanning tree is: \n");
	printMatrix(tree, number_of_vertices, number_of_vertices);

	return 0;
}

// Checks if adding a search edge produces a cycle
int isCycle(int list[], int size, int search) {
	int i;
	for(i = 0; i < size; i++)
		if(list[i] == search)
			return 1;

	return 0;
}

// Prints Matrix
void printMatrix(int mat[SIZE][SIZE], int rows, int cols) {
	int i, j;
	for(i = 0; i < rows; i++) {
		for(j = 0; j < cols; j++)
			printf("%d\t", mat[i][j]);
		printf("\n");
	}
}

// Computes tree according to graph type and returns the minimum weight
int prim(int graph[SIZE][SIZE], int number_of_vertices, int graph_choice) {
	visited_vertices[vertex_count++] = 0;
	int tree_weight = 0;

	while(vertex_count != number_of_vertices) {
		int i, min_value = -1, min_start = 0, min_final = 0, j;
		for(i = 0; i < vertex_count; i++) {
			int cur_vertex = visited_vertices[i];
			for(j = 0; j < number_of_vertices; j++) {
				int cur_weight = graph[cur_vertex][j];
				if(cur_weight > 0 && !isCycle(visited_vertices, vertex_count, j)) {
					if(min_value == -1 || cur_weight < min_value) {
						min_value = cur_weight;
						min_start = cur_vertex;
						min_final = j;
					}
				}
			}
		}

		visited_vertices[vertex_count++] = min_final;
		tree[min_start][min_final] = min_value;
		tree_weight += min_value;
	}

	if(!graph_choice) {
		int i, j;
		for(i = 0; i < number_of_vertices; i++) {
			for(j = 0; j < number_of_vertices; j++) {
				if(tree[i][j] != 0)
					tree[j][i] = tree[i][j];
				else
					tree[i][j] = tree[j][i];
			}
		}
	}

	return tree_weight;
}
