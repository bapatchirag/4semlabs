#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define SIZE 10

// Cost and visited vertex lists
int vertex_distances[SIZE];
int visited[SIZE], visited_count = 0;

// Least cost calculators
void djikstra(int[SIZE][SIZE], int, int);
int findMinCostVertex(int, int);

// Helper functions
int isVisited(int);
void initVertexDistances(int, int);

int main() {
	int number_of_vertices;
	printf("Enter number of vertices in graph: ");
	scanf("%d", &number_of_vertices);

	int graph[SIZE][SIZE];
	int i, j;
	printf("Enter weighted adjacency matrix of graph: \n");
	for(i = 0; i < number_of_vertices; i++)
		for(j = 0; j < number_of_vertices; j++)
			scanf("%d", &graph[i][j]);

	int source_vertex;
	printf("Enter the source vertex number (0 based): ");
	scanf("%d", &source_vertex);

	initVertexDistances(number_of_vertices, source_vertex);
	djikstra(graph, number_of_vertices, source_vertex);

	printf("The shortest distances from source vertex %d to all vertices are: \n", source_vertex);
	for(i = 0; i < number_of_vertices; i++)
		printf("Vertex %d: %d\n", i, vertex_distances[i]);

	return 0;
}

// Checks if search vertex has been visited or not
int isVisited(int search) {
	int i;
	for(i = 0; i < visited_count; i++)
		if(visited[i] == search)
			return 1;
	
	return 0;
}

// Initialises least costs of each vertex to INT_MAX, except for source, which is 0
void initVertexDistances(int number_of_vertices, int source) {
	int i;
	for(i = 0; i < number_of_vertices; i++)
		vertex_distances[i] = (i == source ? 0 : INT_MAX);
}

// Finds the unvisited vertex with the minimum cost
int findMinCostVertex(int number_of_vertices, int source) {
	int i, min_cost_vertex, comp_num = -1;
	for(i = 0; i < number_of_vertices; i++)
		if(!isVisited(i)) {
			if(++comp_num == 0 || vertex_distances[i] < vertex_distances[min_cost_vertex])
				min_cost_vertex = i;
		}

	return min_cost_vertex;
}

// Applies Djikstra's algorithm
void djikstra(int graph[SIZE][SIZE], int number_of_vertices, int source) {
	while(visited_count != number_of_vertices) {
		int cur_source;
		if(visited_count == 1)
			cur_source = source;
		else
			cur_source = findMinCostVertex(number_of_vertices, source);

		int i;
		for(i = 0; i < number_of_vertices; i++) {
			int cur_node_cost = graph[cur_source][i];
			if(cur_node_cost > 0 && cur_node_cost + vertex_distances[cur_source] < vertex_distances[i])
				vertex_distances[i] = cur_node_cost + vertex_distances[cur_source];
		}
		visited[visited_count++] = cur_source;
	}	
}
