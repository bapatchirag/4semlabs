#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 10

// Positions of queens and number of orientations
int position[SIZE], board_count = 0;

// Queen placement functions
int canPlace(int, int);
void arrangeQueens(int, int);

// Helper functions
void printBoard(int[], int);
void printList(int[], int);

int main() {
	int total_queens;
	printf("Enter the number of queens to be placed: ");
	scanf("%d", &total_queens);

	if(total_queens <= 3) {
		printf("No solution possible\n");
		exit(0);
	}

	printf("All possible positions are: \n");
	arrangeQueens(1, total_queens);

	return 0;
}

// Prints appropriate board
void printBoard(int pos[], int size) {
	int i, j;
	for(i = 1; i <= size; i++) {
		for(j = 1; j <= size; j++)
			printf("%c\t", (pos[i] == j ? 'Q': '-'));
		printf("\n");
	}
}

// Checks if queen can be placed at given position
int canPlace(int queen, int pos) {
	int i;
	for(i = 1; i <= queen - 1; i++)
		if(position[i] == pos || abs(position[i] - pos) == abs(i - queen))
			return 0;
	return 1;
}

// Places total_queen queens on the board
void arrangeQueens(int queen, int total_queens) {
	int i;
	for(i = 1; i <= total_queens; i++) {
		if(canPlace(queen, i)) {
			position[queen] = i;

			if(queen == total_queens) {
				printf("Board %d:\n", ++board_count);
				printBoard(position, total_queens);
				printf("\n");
			}
			else
				arrangeQueens(queen+1, total_queens);
		}
	}
}
